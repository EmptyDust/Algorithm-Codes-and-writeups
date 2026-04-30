#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using u128 = unsigned __int128;

using a2 = std::array<i64, 2>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
// const int mod = 1e9 + 7;
const int mod = 998244353;


i64 ask(char dir, int k) {
    std::cout << "? " << dir << ' ' << k << std::endl;
    i64 ret;std::cin >> ret;
    return ret;
}

void solve() {
    int n;std::cin >> n;
    std::vector<a2> points(n);
    for (auto& [x, y] : points) std::cin >> x >> y;
    ranges::sort(points, [&](a2 a, a2 b) {
        if (a[1] - a[0] == b[1] - b[0]) return a[1] > b[1];
        return a[1] - a[0] > b[1] - b[0];
        });
    i64 x1 = points[0][0];
    i64 y1 = points[0][1];
    ranges::sort(points, [&](a2 a, a2 b) {
        if (a[1] + a[0] == b[1] + b[0]) return a[1] > b[1];
        return a[1] + a[0] > b[1] + b[0];
        });
    i64 x2 = points[0][0];
    i64 y2 = points[0][1];

    i64 k = 1'000'000'000;

    ask('L', k);
    ask('L', k);
    ask('U', k);
    ask('U', k);
    auto t1 = ask('U', k);
    ask('R', k);
    ask('R', k);
    ask('R', k);
    auto t2 = ask('R', k);

    i64 b = (t1 + t2 + y1 + y2 - x1 + x2 - 4 * k) / 2;
    i64 a = t2 + y2 - b + x2 - 4 * k;
    b -= 3 * k;
    a += 2 * k;
    // std::cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << '\n';
    std::cout << "! " << a << ' ' << b << std::endl;
}

// x1-a+b-y1 = t1
// a+4k-x2+b-y2 = t2

signed main() {
    int t;std::cin >> t;
    while (t--) {
        solve();
        std::cout << '\n';
    }
    return 0;
}