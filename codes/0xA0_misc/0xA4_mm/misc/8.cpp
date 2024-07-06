#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 1e6 + 10, mod = 1e9 + 7;
using i64 = long long;
using pii = pair<int, int>;
int n, q, k;
vector<int> adj[MAXN];

int k_F[MAXN], F[MAXN];
vector<int> stk, ord;//dfs序
void dfs1(int u, int p) {
    if (stk.size() >= k)
        k_F[u] = stk[stk.size() - k];
    if (!stk.empty())
        F[u] = stk.back();

    stk.push_back(u);
    for (int v : adj[u])if (v != p) {
        dfs1(v, u);
    }
    stk.pop_back();
    ord.push_back(u);
}

vector<int> calc(vector<int> w) {
    vector<int> ret(n + 1);
    for (int i = 1; i <= n; ++i) {
        ret[F[k_F[i]]] -= w[i];
        ret[i] += w[i];
    }
    for (int u : ord)
        ret[F[u]] += ret[u];
    return ret;
}

vector<int> is1[30];
signed main() {
    cin >> n >> q >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs1(1, 0);

    vector<int> cnt(n + 1, 1);cnt = calc(cnt);
    for (int s = 0; s < 30; ++s) {
        vector<int> w(n + 1);
        for (int i = 1; i <= n; ++i)
            w[i] = a[i] >> s & 1;
        is1[s] = calc(w);
    }

    while (q--) {
        int u;cin >> u;
        int x = cnt[u];
        i64 ans = 0;
        for (int s = 0; s < 30; ++s) {
            i64 cur = (1ll * (x - is1[s][u]) * is1[s][u]) % mod;
            ans = (ans + (cur << s) % mod) % mod;
        }
        cout << ans << '\n';
    }
}