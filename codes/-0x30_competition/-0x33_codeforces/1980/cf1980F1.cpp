#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pt = std::pair<i64, i64>;

void solve() {
    i64 n, m, k;std::cin >> n >> m >> k;
    std::vector<pt> pts(k);
    for (auto& [r, c] : pts)std::cin >> r >> c, r--, c--;
    std::vector<int> zbs(k);
    auto cmp = [&](pt a, pt b) {
        if (a.second == b.second)return a.first > b.first;
        return a.second < b.second;
        };
    std::iota(zbs.begin(), zbs.end(), 0);
    std::sort(zbs.begin(), zbs.end(), [&](auto a, auto b) {return cmp(pts[a], pts[b]);});

    std::sort(pts.begin(), pts.end(), cmp);
    i64 curx = 0, cury = 0;
    i64 ans1 = 0;
    std::vector<i64> ans;
    for (auto [r, c] : pts) {
        if (c >= cury && r >= curx) {
            ans1 += (n - curx) * (c - cury);
            ans.push_back(1);
            curx = r + 1;
            cury = c;
        }
        else ans.push_back(0);
        //std::cout << curx << ' ' << cury << ' ' << ans1 << '\n';
    }
    if (n >= curx && m >= cury)
        ans1 += (n - curx) * (m - cury);
    std::cout << ans1 << '\n';
    std::vector<i64> output(k);
    for (int i = 0;i < k;++i)output[zbs[i]] = ans[i];
    for (auto x : output)std::cout << x << ' ';
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