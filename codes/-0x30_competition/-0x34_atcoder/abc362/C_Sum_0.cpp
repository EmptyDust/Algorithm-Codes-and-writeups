#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<i64, i64>;

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int n;std::cin >> n;
    std::vector<pii> ps(n), pre(n);
    i64 l = 0, r = 0;
    for (int i = 0;i < n;++i) {
        auto& [cl, cr] = ps[i];
        std::cin >> cl >> cr;
        l += cl;
        r += cr;
        pre[i] = { l,r };
    }

    if (l > 0 || r < 0) {
        std::cout << "No";
        return 0;
    }
    i64 cur = 0;
    std::vector<i64> ans(n);
    for (int i = n - 1;i >= 1;--i) {
        auto [l, r] = pre[i - 1];
        auto [cl, cr] = ps[i];
        ans[i] = std::min(std::max(cur - l, cl), cr);
        cur -= ans[i];
    }
    ans[0] = cur;
    std::cout << "Yes" << '\n';
    for (auto x : ans)std::cout << x << ' ';
    return 0;
}