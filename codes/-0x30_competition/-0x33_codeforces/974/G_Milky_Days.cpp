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
    i64 n, m, k;std::cin >> n >> m >> k;
    std::vector<pii> ps(n);
    for (auto& [d, a] : ps)std::cin >> d >> a;
    ps.push_back({ inf,0 });
    std::deque<pii> dq;
    i64 ans = 0, c = -1, sum = 0;
    for (auto [d, a] : ps) {
        i64 cnt = d - c;
        while (cnt && sum >= m) {
            i64 cur = 0;
            pii cp;
            while (cur < m) {
                cp = dq.back();
                dq.pop_back();
                cur += cp.second;
                sum -= cp.second;
            }
            i64 use = std::min({ cnt, cur / m, cp.first + k - c });
            ans += use;
            cnt -= use;
            c += use;
            cp.second = cur - use * m;
            dq.push_back(cp);
            sum += cp.second;
            // std::cout << d << ' ' << cp.first << ' ' << ans << ' ' << sum << ' ' << c << '\n';
            while (dq.size() && dq.front().first + k <= c) {
                sum -= dq.front().second;
                dq.pop_front();
            }
        }
        if (c < d) {
            c = d;
            while (dq.size()) {
                sum -= dq.back().second;
                dq.pop_back();
            }
        }
        dq.push_back({ d,a });
        sum += a;
        while (dq.size() && dq.front().first + k <= c) {
            sum -= dq.front().second;
            dq.pop_front();
        }
    }
    std::cout << ans;
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