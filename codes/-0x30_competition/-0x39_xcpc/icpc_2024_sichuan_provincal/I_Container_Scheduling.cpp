#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;
using a4 = std::array<int, 4>;

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int n, l, h;std::cin >> n >> l >> h;
    std::vector<int> xs{ 0 }, ys{ 0 };
    std::vector<a4> ans;
    for (int i = 0;i < n;++i) {
        int x, y;std::cin >> x >> y;
        bool ok = false;
        std::ranges::sort(xs);
        std::ranges::sort(ys);

        auto work = [&](int ax, int ay) {
            // std::cout << ax << ' ' << ay << '\n';
            int bx = ax + x, by = ay + y;
            if (bx > l || by > h || ok)return;
            for (auto [tx, ty, kx, ky] : ans) if (tx != -1) {
                int jx1 = std::max(tx, ax), jx2 = std::min(kx, bx);
                int jy1 = std::max(ty, ay), jy2 = std::min(ky, by);
                if (jx2 > jx1 && jy2 > jy1) return;
            }
            ans.push_back({ ax,ay,bx,by });
            xs.push_back(bx);
            ys.push_back(by);
            ok = true;
            };

        for (int ax : xs)for (int ay : ys) work(ax, ay);
        if (!ok) ans.push_back({ -1 });
    }
    for (auto [x, y, _, __] : ans) {
        if (x == -1)std::cout << -1 << '\n';
        else std::cout << x << ' ' << y << '\n';
    }
    return 0;
}