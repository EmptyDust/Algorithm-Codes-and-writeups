#include <bits/stdc++.h>
#define int long long 
using namespace std;
constexpr int MAXN = 1e6 + 10;
vector<int> adj[MAXN];

signed main() {
    ios::sync_with_stdio(false);
    int n, m;cin >> n >> m;
    int u, v;
    while (m--) {
        cin >> u >> v;u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 0;i < n;++i)
        return 0;
}