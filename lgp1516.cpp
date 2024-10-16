#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<int, int>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
// const int mod = 1e9 + 7;
const int mod = 998244353;

void exGCD(int a, int b, int& x, int& y) {
    if (!b) x = 1, y = 0;
    else exGCD(b, a % b, y, x), y -= a / b * x;
}

void solve() {
    int x, y;
    exGCD(14212, 20, x, y);
    std::cout << x << ' ' << y << ' ' << std::__gcd(x, y);
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