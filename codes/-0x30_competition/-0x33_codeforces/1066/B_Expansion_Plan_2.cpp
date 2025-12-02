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
    i64 n, x, y;std::cin >> n >> x >> y;
    if (x < 0) x = -x;
    if (y < 0) y = -y;
    std::string s;std::cin >> s;
    int cnt4 = ranges::count(s, '4');
    int cnt8 = ranges::count(s, '8');
    x = std::max(0ll, x - cnt8);
    y = std::max(0ll, y - cnt8);
    std::cout << (x + y <= cnt4 ? "YES" : "NO");
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