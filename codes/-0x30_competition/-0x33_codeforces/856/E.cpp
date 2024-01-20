#include<bits/stdc++.h>
#define int long long
using namespace std;

constexpr int MAXN = 1e5;
vector<int> p[MAXN], ans[MAXN];
int vis[MAXN], c[MAXN], f;

void bfs(int x) {
    queue<int> q;
    q.push(x);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : p[u]) {
            if (vis[v])continue;
            vis[v] = 1;
            c[v] = c[u] + 1;
            f = max(f, c[v]);
            q.push(v);
            ans[c[v]].push_back(v);
        }
    }
}

void solve() {
    int n, m;cin >> n >> m;f = 1;
    for (int i = 1;i <= n;++i)vis[i] = 0, p[i].clear(), ans[i].clear();
    while (m--) {
        int a, b;
        cin >> a >> b;
        p[b].push_back(a);
    }
    vis[1] = 1, c[1] = 1;ans[1].push_back(1);
    bfs(1);
    bool finite = true;
    int res = 0;
    for (int i = 1;i <= n;++i) {
        if (!vis[i])finite = false;
        res += c[i];
    }
    if (!finite) {
        cout << "INFINITE";
        return;
    }
    cout << "FINITE" << '\n' << res << '\n';
    for (int i = f;i >= 1;--i) {
        for (int j : ans[i]) {
            cout << j << ' ';
            ans[i - 1].push_back(j);
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t;cin >> t;
    while (t--) { solve();cout << '\n'; }
    return 0;
}