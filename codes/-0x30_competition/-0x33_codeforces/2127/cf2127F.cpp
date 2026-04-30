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

}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int m = 6;
    std::vector<int> a(4);
    int ans = 0;
    auto dfs = [&](auto&& dfs, int pos = 0) ->void {
        if (pos == 4) {
            i64 res = 0;
            if (std::accumulate(a.begin(), a.end(), 0) != m || ranges::max(a) != a[3]) return;
            bool f = 1;
            for (auto x : a) {
                if (f) res += a[3] - x, f = 0;
                if (x == a[3])f = 1;
            }
            for (auto x : a)std::cout << x << ' ';std::cout << res << '\n';
            ans += res;
            return;
        }
        for (int i = 0;i <= m;++i) {
            a[pos] = i;
            dfs(dfs, pos + 1);
        }
        };
    dfs(dfs);
    std::cout << ans << ' ';
    // int t;std::cin >> t;
    // while (t--) {
    //     solve();
    //     std::cout << '\n';
    // }
    return 0;
}