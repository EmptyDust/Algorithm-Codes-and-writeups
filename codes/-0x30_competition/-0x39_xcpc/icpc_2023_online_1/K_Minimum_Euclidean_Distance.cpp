#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<double, double>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
// const int mod = 1e9 + 7;
const int mod = 998244353;

#define x first
#define y second

double cross(pii b, pii a, pii c = { 0,0 }) {
    return ((a.x - c.x) * (b.y - c.y)) - ((a.y - c.y) * (b.x - c.x));
}

void print(pii a) {
    std::cout << a.x << ' ' << a.y << '\n';
}

pii jiao(double k1, double b1, double k2, double b2) {
    double t1 = b1 * k2 / k1;
    double y = (t1 - b2) / (k2 / k1 - 1);
    double x = (y - b1) / k1;
    return { x,y };
}

pii get_c(pii a, pii b, pii c) {
    if (a.x == b.x) {
        return { a.x,c.y };
    }
    if (a.y == b.y) {
        return { c.x,a.y };
    }
    double k1 = (b.y - a.y) / (b.x - a.x);
    double b1 = b.y - k1 * b.x;
    double k2 = -1 / k1;
    double b2 = c.y - k2 * c.x;
    // print(a);print(b);
    // std::cout << k1 << ' ' << b1 << ' ' << k2 << " " << b2 << ' ';
    print(jiao(k1, b1, k2, b2));
    return jiao(k1, b1, k2, b2);
}

#define PI acos(-1)
double cal(pii p, pii c, double d) {
    // print(p);print(c);
    return ((p.x - c.x) * (p.x - c.x) + (p.y - c.y) * (p.y - c.y) + d * d + PI * d * d * d * d / 12) / (PI * d * d);
}

void solve() {
    int n, q;std::cin >> n >> q;
    std::vector<pii> ps(n);
    for (auto& [x, y] : ps)std::cin >> x >> y;
    auto check = [&](pii c) {
        bool ok = true;
        for (int i = 0;i < n;++i) {
            if (!cross(c, ps[(i + 1) % n], ps[i])) {
                ok = false;
                break;
            }
        }
        // std::cout << ok << ' ';
        return ok;
        };
    while (q--) {
        double d;
        pii a, b, c;
        std::cin >> a.x >> a.y >> b.x >> b.y;
        c.x = (a.x + b.x) / 2;
        c.y = (a.y + b.y) / 2;
        d = std::sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y)) / 2.0;
        double ans = 1e9;
        if (check(c))ans = cal(c, c, d);
        else for (int i = 0;i < n;++i) {
            ans = std::min(ans, cal(ps[i], c, d));
            ans = std::min(ans, cal(get_c(ps[i], ps[(i + 1) % n], c), c, d));
        }
        std::cout << ans << "\n";
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    std::cout.precision(13);
    int t = 1;
    while (t--) {
        solve();
        std::cout << '\n';
    }
    return 0;
}