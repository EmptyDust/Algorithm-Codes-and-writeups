#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back

using namespace std;
typedef pair<int, int> PII;
typedef long long LL;

struct Tarjan {
    int n, cnt, tp, dfn;
    vector<LL> in, low, in_sk, sk, scc, ans, sum, sb;
    vector<vector<PII>>& e;
    Tarjan(int n, vector<vector<PII>>& e) : n(n), e(e) {
        in.assign(n + 5, 0);
        sb = sum = ans = low = in_sk = sk = scc = in;
        dfn = cnt = tp = 0;
        for (int i = 0; i < n; i++) if (!in[i]) dfs(i);

        vector<vector<int>> fuck(cnt + 5);
        in.assign(cnt + 5, 0);
        for (int i = 0; i < n; i++) {
            int u = scc[i];
            for (auto [j, w] : e[i]) {
                int v = scc[j];
                if (u == v) continue;
                fuck[v].pb(u); in[u]++;
            }
        }
        queue<int> que;
        for (int i = 1; i <= cnt; i++) if (!in[i]) que.push(i);
        while (que.size()) {
            int u = que.front(); que.pop();
            for (auto v : fuck[u]) {
                sb[v] |= sb[u];
                in[v]--;
                if (!in[v]) que.push(v);
            }
        }
        for (int i = 0; i < n; i++) ans[i] = sb[scc[i]];
    }
    void dfs(int u) {
        in[u] = low[u] = ++dfn;
        sk[++tp] = u; in_sk[u] = true;
        for (auto [v, w] : e[u]) {
            if (!in[v]) {
                sum[v] = sum[u] + w;
                dfs(v);
            }
            if (in_sk[v]) {
                if (in[v] <= in[u]) {
                    if (sum[u] - sum[v] + w != 0) ans[u] = true;
                }
                low[u] = min(low[u], low[v]);
            }
        }
        if (in[u] == low[u]) {
            ++cnt;
            while (1) {
                int v = sk[tp--];
                sb[cnt] |= ans[v];
                scc[v] = cnt;
                in_sk[v] = false;
                if (v == u) break;
            }
        }
    }
};

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<PII>> e(n + 5);
    for (int i = 1; i <= m; i++) {
        int a, b; cin >> a >> b;
        int u = (a % n + n) % n;
        int v = ((a + b) % n + n) % n;
        e[u].pb({ v, b });
        // cout << u << ' ' << v << ' ' << b << "\n";
    }

    Tarjan tj(n, e);

    while (q--) {
        int x; cin >> x;
        x = (x % n + n) % n;
        if (tj.ans[x]) cout << "Yes\n";
        else cout << "No\n";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    // cin >> tt;
    while (tt--) solve();
    return 0;
}
/*
g++ 1.cpp -o 1 && ./1 < in.txt > out.txt
*/