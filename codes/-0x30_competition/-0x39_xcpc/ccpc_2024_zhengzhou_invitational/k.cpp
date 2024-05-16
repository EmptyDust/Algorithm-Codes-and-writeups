#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
int nums[MAXN], n, st[MAXN];
using pt = std::pair<int, int>;
std::vector<int> adj[MAXN];

bool dfs1(int x, int p) {
    bool f = nums[x] * 2 >= nums[p];
    for (int nxt : adj[x])if (nxt != p) {
        f &= dfs1(nxt, x);
    }
    return st[x] = f;
}

int ans = 0;
void dfs2(int x, int p) {
    if (p && nums[p] * 2 < nums[x])return;
    int cnt = 0;
    for (int nxt : adj[x])if (nxt != p) {
        cnt += st[nxt] == 0;
    }
    if (cnt >= 2)return;
    if (cnt == 0) {
        ans++;
        for (int nxt : adj[x])if (nxt != p) {
            dfs2(nxt, x);
        }
    }
    else {
        for (int nxt : adj[x])if (nxt != p && st[nxt] == 0) {
            dfs2(nxt, x);
        }
    }
}

void solve() {
    std::cin >> n;
    for (int i = 0;i <= n;++i) {
        adj[i].clear();
        st[i] = 0;
        ans = 0;
    }
    for (int i = 1;i <= n;++i)
        std::cin >> nums[i];
    int u, v;
    for (int i = 1;i < n;++i) {
        std::cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs1(1, 0);
    dfs2(1, 0);
    std::cout << ans;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t;std::cin >> t;
    while (t--) {
        solve();
        std::cout << '\n';
    }
    return 0;
}