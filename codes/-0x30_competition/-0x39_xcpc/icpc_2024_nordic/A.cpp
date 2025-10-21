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

const int P = 1e4 + 1;

void solve() {
    int x1, y1, x2, y2, mx, my;
    std::cin >> x1 >> y1 >> x2 >> y2 >> mx >> my;
    if (x1 <= mx && x2 <= mx) {
        std::cout << 2 << '\n';
        std::cout << -P << ' ' << y1 << '\n';
        std::cout << -P << ' ' << y2 << '\n';
        return;

    }
    if (mx <= x1 && mx <= x2) {
        std::cout << 2 << '\n';
        std::cout << P << ' ' << y1 << '\n';
        std::cout << P << ' ' << y2 << '\n';
        return;
    }
    if (y1 <= my && y2 <= my) {
        std::cout << 2 << '\n';
        std::cout << x1 << ' ' << -P << '\n';
        std::cout << x2 << ' ' << -P << '\n';
        return;
    }
    if (my <= y1 && my <= y2) {
        std::cout << 2 << '\n';
        std::cout << x1 << ' ' << P << '\n';
        std::cout << x2 << ' ' << P << '\n';
        return;
    }
    if (x1 < x2 && y1 < y2) {
        std::cout << 3 << '\n';
        std::cout << -P << ' ' << y1 << '\n';
        std::cout << -P << ' ' << P << '\n';
        std::cout << x2 << ' ' << P << '\n';
    }
    else if (x1 > x2 && y1 < y2) {
        std::cout << 3 << '\n';
        std::cout << P << ' ' << y1 << '\n';
        std::cout << P << ' ' << P << '\n';
        std::cout << x2 << ' ' << P << '\n';
    }
    else if (x1 > x2 && y1 > y2) {
        std::cout << 3 << '\n';
        std::cout << x1 << ' ' << P << '\n';
        std::cout << -P << ' ' << P << '\n';
        std::cout << -P << ' ' << y2 << '\n';
    }
    else {
        std::cout << 3 << '\n';
        std::cout << x1 << ' ' << P << '\n';
        std::cout << P << ' ' << P << '\n';
        std::cout << P << ' ' << y2 << '\n';
    }
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