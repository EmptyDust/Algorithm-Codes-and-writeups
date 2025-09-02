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

// 3 9 18 36
// 3 5 6 

// 3 9
// 3 -4 -5 -6 7 8 9

void solve() {
    int l, r;std::cin >> l >> r;
    int x = l + (l % 2 == 0);
    // std::cout << x << ' ';
    if (x * 2 > r) {
        // std::cout << ((r - l + 1)) << '\n';
        std::cout << ((r - l + 1) % 2 ? "Alice" : "Bob");
        return;
    }
    std::cout << ((l % 2) ? "Alice" : "Bob");
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