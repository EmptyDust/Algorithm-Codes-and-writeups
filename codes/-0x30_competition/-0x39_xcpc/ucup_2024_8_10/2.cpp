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

i64 sqrtl(i64 x) {
    i64 l = 1, r = 1e9 + 1;
    while (l < r) {
        auto mid = l + r >> 1;
        if (mid * mid >= x)r = mid;
        else l = mid + 1;
    }
    return l;
}

// std::vector<pii> cal(i64 x) {
//     std::vector<pii> res;
//     for (i64 l = 1, r = std::sqrtl(x);l <= r;) {
//         i64 tmp = l * l + r * r;
//         if (tmp == x) {
//             res.push_back({ l,r });
//             res.push_back({ l,-r });
//             res.push_back({ -l,r });
//             res.push_back({ -l,-r });
//             res.push_back({ r,l });
//             res.push_back({ r,-l });
//             res.push_back({ -r,l });
//             res.push_back({ -r,-l });
//             l++, r--;
//         }
//         else if (tmp > x)r--;
//         else l++;
//     }
//     // std::cout << res.size() << '\n';
//     return res;
// }

// i64 getdis(i64 ax, i64 ay, i64 bx, i64 by) {
//     return (ax - bx) * (ax - bx) + (ay - by) * (ay - by);
// }

void solve() {
    i64 A, B, C, D;std::cin >> A >> B >> C >> D;
    i64 ax = 0;
    i64 ay = sqrtl(A);
    //bx ^ 2 + (by - ay) ^ 2 = dx ^ 2 + (dy - ay) ^ 2
    //(bx - cx) ^ 2 + (by - cy) ^ 2 = bx ^ 2 + (by - ay) ^ 2 
    // - 2 * bx * cx + C - 2 * by * cy = - 2 * ay * by + ay * ay
    // - 2 * bx * cx = 2 * (cy - ay) * by - C + ay * ay
    //B - 2 * ay * by + ay * ay = D - 2 * ay * dy + ay * ay
    //B - D = 2 * ay * (by - dy)
    //(bx - cx) ^ 2 + (by - cy) ^ 2 = (dx - cx) ^ 2 + (dy - cy) ^ 2
    // bx * bx - 2 * bx * cx + by * by - 2 * by * cy = dx * dx - 2 * cx * dx + dy * dy - 2 * dy * cy
    // B - 2 * bx * cx  = D - 2 * cx * dx + 2 * cy * (by - dy)
    // B - D = 2 * cx * (bx - dx) + 2 * cy * (by - dy)
    // 2 * ay * (by - dy) = 2 * cx * (bx - dx) + 2 * cy * (by - dy)
    i64 cx = (B - D) / 2 / ay;
    i64 cy = sqrtl(C - cx * cx);
    i64 n = (cy - ay - cx + ax) / 2;
    i64 m = (cy - ay + cx - ax) / 2;
    // std::cout << n << ' ' << m << '\n';

    //n + m = ax - cx;
    //n - m = ay - cy;

    i64 bx = ax - n;
    i64 by = ay + m;
    i64 dx = ax + m;
    i64 dy = ay + n;
    std::cout << ay << ' ' << bx << ' ' << by << ' ' << cx << ' ' << cy << ' ' << dx << ' ' << dy << '\n';
    // std::vector<pii> a{ {0,std::sqrtl(A)} };
    // auto b = cal(B);
    // auto c = cal(C);
    // auto d = cal(D);
    // for (auto [ax, ay] : a)
    //     for (auto [bx, by] : b)
    //         for (auto [cx, cy] : c)
    //             for (auto [dx, dy] : d) {
    //                 auto dis1 = getdis(ax, ay, bx, by);
    //                 auto dis2 = getdis(bx, by, cx, cy);
    //                 auto dis3 = getdis(cx, cy, dx, dy);
    //                 auto dis4 = getdis(dx, dy, ax, ay);
    //                 // std::cout << ay << ' ' << bx << ' ' << by << ' ' << cx << ' ' << cy << ' ' << dx << ' ' << dy << '\n';
    //                 if (dis1 == dis2 && dis2 == dis3 && dis3 == dis4) {
    //                     std::cout << ay << ' ' << bx << ' ' << by << ' ' << cx << ' ' << cy << ' ' << dx << ' ' << dy << '\n';
    //                     return;
    //                 }
    //             }
    // std::cout << "error";
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}