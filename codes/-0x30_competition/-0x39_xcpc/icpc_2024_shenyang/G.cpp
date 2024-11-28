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

void solve() {
    int n;std::cin >> n;
    std::vector<pii> a(n);
    for (auto& [x, y] : a)std::cin >> x >> y;
    ranges::sort(a);
    double ans = 0, lst = 0;
    auto query = [&](int p, int q) {
        int g = std::__gcd(p, q);
        p /= g, q /= g;
        std::cout << "? " << p << ' ' << q << std::endl;
        long double x, y;std::cin >> x >> y;
        return 1.0 * x / y;
        };
    bool f = 0;
    for (int i = 1;i + 1 < n;++i) {
        if (a[i].first == a[i - 1].first) {
            f = 1;
            continue;
        }
        if (f) {
            double
                l = query(a[i].first + a[i - 1].first * 2, 3),
                r = query(a[i].first * 2 + a[i - 1].first, 3);
            ans += (l + r) * (a[i].first - a[i - 1].first);
            lst = r * 2 - l;
            f = 0;
        }
        else {
            double m = query(a[i].first + a[i - 1].first, 2);
            ans += m * 2 * (a[i].first - a[i - 1].first);
            lst = m * 2 - lst;
        }
    }
    if (f && a[n - 1].first != a[n - 2].first) {
        double m = query(a[n - 1].first + a[n - 2].first, 2);
        lst = m * 2;
    }
    ans += lst * (a[n - 1].first - a[n - 2].first);
    int ai = round(ans);
    if (ai % 2)std::cout << "! " << ai << ' ' << 2 << std::endl;
    else std::cout << "! " << ai / 2 << ' ' << 1 << std::endl;
}

signed main() {
    int t;std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

