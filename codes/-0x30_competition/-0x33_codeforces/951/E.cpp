#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pt = std::pair<int, int>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

void solve() {
    int n, d;
    std::cin >> n >> d;
    std::vector<pt> pts(n);
    for (auto& [x, y] : pts)std::cin >> x >> y;

    int I = 0, J = 0, K = 0;
    auto work = [&]() {
        std::vector<a3> a;a.reserve(n);
        for (int i = 0;i < n;++i) {
            auto [x, y] = pts[i];
            a.push_back({ x + y ,x ,i });
        }
        std::sort(a.begin(), a.end());

        std::vector<a4> b;
        for (auto& [s, x, i] : a) {
            auto it = std::lower_bound(a.begin(), a.end(), std::array{ s , x + d / 2 , 0 });
            if (it != a.end() && (*it)[0] == s && (*it)[1] == x + d / 2) {
                b.push_back({ s,x, i, (*it)[2] });
            }
        }

        for (auto& [s, x, i] : a) {
            auto it = std::lower_bound(b.begin(), b.end(), std::array{ s + d, x ,0,0 });
            if (it != b.end() && (*it)[0] == s + d && (*it)[1] <= x + d / 2) {
                I = i + 1, J = (*it)[2] + 1, K = (*it)[3] + 1;
                break;
            }
        }
        };

    for (int i = 0;i < 4;++i) {
        work();
        if (I > 0)break;
        for (auto& [x, y] : pts) {
            std::swap(x, y);
            x = -x;
        }
    }
    std::cout << I << ' ' << J << ' ' << K;
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