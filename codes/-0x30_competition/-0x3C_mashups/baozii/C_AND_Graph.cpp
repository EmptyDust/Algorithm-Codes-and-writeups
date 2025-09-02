#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using u128 = unsigned __int128;

using a2 = std::array<int, 2>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
// const int mod = 1e9 + 7;
const int mod = 998244353;

void solve() {
    int n, m;std::cin >> n >> m;
    int mask = (1 << n) - 1;
    std::vector<bool> a(1 << n);
    for (int i = 0;i < m;++i) {
        int x;
        std::cin >> x;
        a[x] = 1;
    }
    std::vector<bool> vis(2 * (1 << n));
    auto dfs = [&](auto&& dfs, int u)->void {
        if (vis[u])return;
        vis[u] = 1;
        if (u < (1 << n)) {
            for (int j = 0;j < n;++j) {
                if (!(u >> j & 1)) {
                    dfs(dfs, u ^ (1 << j));
                }
            }
            if (a[mask ^ u]) dfs(dfs, (mask ^ u) + (1 << n));
        }
        else {
            dfs(dfs, u - (1 << n));
        }
        };
    int ans = 0;
    for (int i = 0;i < (1 << n);++i) if (a[i]) {
        if (!vis[(1 << n) + i]) {
            ans++;
            dfs(dfs, (1 << n) + i);
        }
    }
    std::cout << ans;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t = 1;
    while (t--) {
        solve();
        std::cout << '\n';
    }
    return 0;
}