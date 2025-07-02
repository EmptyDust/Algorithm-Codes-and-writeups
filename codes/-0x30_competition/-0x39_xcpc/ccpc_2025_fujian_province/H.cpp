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
    i64 n;std::cin >> n;
    std::vector<i64> ans;
    while (std::__popcount(n) != 1) {
        ans.push_back((n & -n));
        n += (n & -n);
    }
    // std::cout << (n & -n);
    if (std::__lg(n) % 2)ans.push_back(n);
    // std::cout << std::__lg(n) << ' ';
    std::cout << ans.size() << '\n';
    for (auto x : ans)std::cout << x << ' ';std::cout << '\n';
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t;std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}