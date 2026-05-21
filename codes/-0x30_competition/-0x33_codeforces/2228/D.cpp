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
    int n;
    std::cin >> n;
    std::vector<a2> points(n);
    for (auto &[x, y] : points)
        std::cin >> x >> y;
    ranges::sort(points);
    std::vector<int> cnt(n + 1), cntr(n + 1);
    int lmin = n + 1, lmax = -1, lsize = 0;
    int rmin = n + 1, rmax = -1, rsize = 0;
    for (auto &[x, y] : points) {
        rmin = std::min(rmin, y);
        rmax = std::max(rmax, y);
        rsize++;
        cntr[y]++;
        cnt[y] = 1;
    }
    for (int i = 1; i <= n; ++i)
        cnt[i] += cnt[i - 1];
    i64 ans = 0;
    auto work = [&]() {
        if (lsize == 0 || rsize == 0)
            return;
        int min = std::max(lmin, rmin);
        int max = std::min(lmax, rmax);
        // std::cout << min << ' ' << max << '\n';
        if (min >= max)
            return;
        int c = cnt[max] - cnt[min];
        ans += c;
    };
    for (int i = 0, cur = -1; i < n; ++i) {
        auto [x, y] = points[i];
        if (x != cur) {
            // std::cout << i << ' ' << y << '\n';
            work();
            cur = x;
        }
        // std::cout << lmin << ' ' << lmax << ' ' << rmin << ' ' << rmax << "\n";

        rsize--;
        cntr[y]--;
        while (rmax >= 0 && cntr[rmax] == 0)
            rmax--;
        while (rmin <= n && cntr[rmin] == 0)
            rmin++;

        lsize++;
        lmin = std::min(lmin, y);
        lmax = std::max(lmax, y);
    }
    std::cout << ans << '\n';
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}