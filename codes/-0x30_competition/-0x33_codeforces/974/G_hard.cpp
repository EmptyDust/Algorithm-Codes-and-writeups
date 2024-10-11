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
    std::deque<pii> dq;
    i64 ans = 0, c = -1, sum = 0;
    for (int i = 0;i < n;++i) {
        i64 d, a;
        std::cin >> d >> a;
        dq.push_back({ d,a });
        if (c < d)
            c = d;
        sum += a;
        while (dq.size() && dq.front().first + k <= c) {
            sum -= dq.front().second;
            dq.pop_front();
        }
        while (sum >= m) {
            i64 cur = 0;
            pii cp;
            i64 mx = dq.front().first + k;
            while (cur < m) {
                cp = dq.front();
                dq.pop_front();
                cur += cp.second;
                sum -= cp.second;
            }
            int nc = std::min(c + cur / m, mx);
            cp.second = cur - (nc - c) * m;
            sum += cp.second;
            dq.push_front(cp);
            ans += nc - c;
            c = nc;
            while (dq.size() && dq.front().first + k <= c) {
                sum -= dq.front().second;
                dq.pop_front();
            }
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