#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using f64 = long double;

using pii = std::pair<int, int>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
// const int mod = 1e9 + 7;
const int mod = 998244353;

// using i128 = __int128;

// std::ostream& operator<<(std::ostream& os, i128 n) {
//     std::string s;
//     while (n) {
//         s += '0' + n % 10;
//         n /= 10;
//     }
//     std::reverse(s.begin(), s.end());
//     return os << s;
// }

// i128 sqrtl(i128 x) {
//     i64 lo = 0, r = 1e15;
//     while (lo < r) {
//         i128 mid = lo + r + 1 >> 1;
//         if (mid * mid <= x) {
//             lo = mid;
//         }
//         else {
//             r = mid - 1;
//         }
//     }
//     return r + 1;
// };

f64 eps = 1e-11;
f64 sqrtl(f64 x) {
    f64 l = 0, r = 2e8 + 10;
    while (l + eps < r) {
        auto mid = (l + r) / 2;
        if (mid >= x / mid)r = mid;
        else l = mid + eps;
    }
    return l;
}

struct Poly
{
    int sz;
    std::vector<pii> points;
    Poly(int n) { sz = n;points.resize(n);init(); }
    void init() {
        for (auto& [x, y] : points)std::cin >> x >> y;
    }
    f64 distance(int a, int b) {
        // std::cout << points[a].first << '\n';
        return std::sqrtl(1ll * (points[a].first - points[b].first) * (points[a].first - points[b].first)
            + 1ll * (points[a].second - points[b].second) * (points[a].second - points[b].second));
    }
    f64 diametre() {
        f64 res = 0;
        for (int i = 0, j = 0;i < sz;++i) {
            while (j < sz && distance(i, j + 1) > distance(i, j))j++;
            if (j < sz)
                res = std::max(res, distance(i, j));
            // std::cout << distance(i, j) << ' ';
            // std::cout << i << " " << j << "\n";
        }
        return res;
    }
    f64 preimetre() {
        f64 res = distance(0, sz - 1);
        for (int i = 0;i < sz - 1;++i)res += distance(i, i + 1);
        return res;
    }
    f64 cal(f64 x) {
        f64 res = 0;
        if (distance(0, sz - 1) - 2 * x > 0)res += distance(0, sz - 1) - 2 * x;
        for (int i = 0;i < sz - 1;++i)if (distance(i, i + 1) - 2 * x > 0)
            res += distance(i, i + 1) - 2 * x;
        return res;
    }
};


void solve() {
    int n;std::cin >> n;
    Poly a(n);
    int m;std::cin >> m;
    Poly b(m);
    f64 d = b.diametre();
    // std::cout << d << '\n';
    const f64 pi = 3.1415926535897932384626;
    f64 ans = a.preimetre() + 2 * d * pi + b.cal(d);
    std::cout << ans;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    std::cout.precision(25);
    int t;std::cin >> t;
    while (t--) {
        solve();
        std::cout << '\n';
    }
    return 0;
}