#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10;
int nums[MAXN], n;
using pt = std::pair<int, int>;
std::vector<int> adj[MAXN];

int check(int x) {
    int cnt = 0;
    std::function<int(int, int)> dfs = [&](int now, int par)->int {
        int ret = 1;
        for (int nxt : adj[now])if (nxt != par) {
            ret += dfs(nxt, now);
        }
        if (ret >= x)cnt++, ret = 0;
        return ret;
        };
    dfs(0, -1);
    return cnt - 1;
}

void solve() {
    int n, k;std::cin >> n >> k;
    for (int i = 0;i < n;++i)adj[i].clear();
    int u, v;
    for (int i = 1;i < n;++i) {
        std::cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    auto l = 1, r = n;
    while (l < r) {
        auto mid = l + r + 1 >> 1;
        if (check(mid) >= k)l = mid;
        else r = mid - 1;
    }
    std::cout << l;
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