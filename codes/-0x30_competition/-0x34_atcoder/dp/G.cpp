#include <bits/stdc++.h>
#define int long long 
using namespace std;
constexpr int MAXN = 1e6 + 10;
int dp[MAXN];
vector<int> adj[MAXN];

int dfs(int x) {
    int& cur = dp[x];
    if (~cur)return cur;
    cur = 0;
    for (int nxt : adj[x]) {
        cur = max(cur, dfs(nxt) + 1);
    }
    return cur;
}

signed main() {
    ios::sync_with_stdio(false);
    memset(dp, -1, sizeof dp);
    int n, m;cin >> n >> m;
    int u, v;
    while (m--) {
        cin >> u >> v;
        adj[u].push_back(v);
    }
    for (int i = 1;i <= n;++i)if (!~dp[i])
        dfs(i);
    cout << *max_element(dp + 1, dp + n + 1);
    return 0;
}