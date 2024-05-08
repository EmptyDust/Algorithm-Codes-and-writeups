#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
int n, k;
using pt = std::pair<int, int>;

int cal(pt& p, pt& mid) {
    auto& [x, y] = p;
    auto& [mx, my] = mid;
    if (x <= mx && y <= my)return 0;
    if (x <= mx && y > my)return 1;
    if (x > mx && y > my)return 2;
    if (x > mx && y <= my)return 3;
    return -1;
}

int cal2(int x, int dir) {
    x = (x + 4 - dir) % 4;
    if (x == 0)x += 4;
    return x;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n >> k;
    std::vector<pt> pts(n);
    for (auto& [x, y] : pts)std::cin >> x >> y;
    std::sort(pts.begin(), pts.end(), [&](pt a, pt b) {
        if (a == b)return a > b;
        int dir = 0;
        bool f = 0;//left
        pt mid = { 1 << (k - 1),1 << (k - 1) };
        for (int i = k;i > 0;--i) {
            int xa = cal(a, mid), xb = cal(b, mid);
            if (xa == xb) {
                int move = 1 << (i - 2);
                switch (xa)
                {
                case 0:
                    mid.first -= move;
                    mid.second -= move;
                    break;
                case 1:
                    mid.first -= move;
                    mid.second += move;
                    break;
                case 2:
                    mid.first += move;
                    mid.second += move;
                    break;
                case 3:
                    mid.first += move;
                    mid.second -= move;
                    break;
                }
                int tmp = cal2(xa, dir);
                if (tmp == 4) {
                    f = !f;
                    dir = (dir + 3) % 4;
                }
                if (tmp == 1) {
                    f = !f;
                    dir = (dir + 1) % 4;
                }
                continue;
            }
            //std::cout << "a:" << a.first << ' ' << a.second << '\n';
            //std::cout << "b:" << b.first << ' ' << b.second << '\n';

            xa = cal2(xa, dir);
            xb = cal2(xb, dir);
            //std::cout << xa << ' ' << xb << ' ' << dir << '\n';
            return f ? xa < xb : xa > xb;
        }
        return a > b;
        });
    for (auto& [x, y] : pts)std::cout << x << ' ' << y << '\n';
    return 0;
}