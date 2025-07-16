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
    int n;std::cin >> n;
    std::vector<int> a(n);
    for (int& x : a)std::cin >> x;
    int y = 1;
    for (int i = n - 2;i >= 0;--i) {
        if (a[i + 1] % a[i] == 0) continue;
        auto gcd = std::__gcd(a[i + 1], a[i]);
        auto x = a[i] / gcd;
        y = x * y / std::__gcd(x, y);
        a[i] /= y;
    }
    // for (auto x : a)std::cout << x << ' ';std::cout << '\n';
    std::cout << y;
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