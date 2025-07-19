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

void solve() {
    int W, H;std::cin >> W >> H;
    int x1, y1, x2, y2;std::cin >> x1 >> y1 >> x2 >> y2;
    int w, h;std::cin >> w >> h;
    int min = 1e9;
    if (w + (x2 - x1) <= W) {
        if (w <= x1) min = 0;
        else min = std::min(min, w - x1);
        if (x2 <= W - w) min = 0;
        else min = std::min(min, x2 - (W - w));
    }
    if (h + (y2 - y1) <= H) {
        if (h <= y1) min = 0;
        else min = std::min(min, h - y1);
        if (y2 <= H - h) min = 0;
        else min = std::min(min, y2 - (H - h));
    }
    std::cout << (min == 1e9 ? -1 : min);
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