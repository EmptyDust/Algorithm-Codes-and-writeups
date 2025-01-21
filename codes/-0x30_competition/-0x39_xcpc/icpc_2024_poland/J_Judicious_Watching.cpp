#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<i64, i64>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
// const int mod = 1e9 + 7;
const int mod = 998244353;

void solve() {
    int n, m, k;std::cin >> n >> m >> k;
    std::vector<pii> hw(n);
    for (auto& [_, a] : hw)std::cin >> a;
    for (auto& [d, _] : hw)std::cin >> d;
    ranges::sort(hw, std::greater<pii>());
    std::vector<pii> info;info.reserve(n);
    i64 cur = 1e18;
    for (auto [d, a] : hw) {
        cur = std::min(cur, d);
        cur -= a;
        info.push_back({ cur + 1,a });
        // std::cout << cur + 1 << ' ' << a << "\n";
    }
    std::reverse(info.begin(), info.end());
    std::vector<i64> b(m), pre(n);
    for (auto& x : b)std::cin >> x;
    for (int i = 1;i < m;++i)b[i] += b[i - 1];
    for (int i = 0;i < n;++i) {
        if (i)pre[i] = pre[i - 1];
        pre[i] += info[i].second;
    }
    while (k--) {
        i64 x;std::cin >> x;
        auto l = 0, r = n;
        while (l < r) {
            auto mid = l + r >> 1;
            if (info[mid].first > x)r = mid;
            else l = mid + 1;
        }
        // std::cout << l << ' ';
        i64 mi = 0;
        l--;
        if (l >= 0) {
            if (l > 0)mi += pre[l - 1];
            mi += std::min(info[l].second, x - info[l].first + 1);
        }
        // std::cout << x - mi << ' ';
        int ans = std::upper_bound(b.begin(), b.end(), x - mi) - b.begin();
        std::cout << ans << ' ';
    }
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
