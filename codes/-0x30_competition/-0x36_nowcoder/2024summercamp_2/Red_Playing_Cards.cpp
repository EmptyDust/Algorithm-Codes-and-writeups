#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<i64, i64>;
using a3 = std::array<i64, 3>;

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    i64 n;std::cin >> n;
    std::vector<i64> a(2 * n);
    for (auto& x : a)std::cin >> x;
    std::vector<pii> poss(n + 1, { -1,-1 });
    std::vector<a3> a3s;
    std::vector<i64> res(n + 1);
    {
        std::set<i64> st;
        for (int i = 2 * n - 1;i >= 0;--i) {
            if (poss[a[i]].second == -1)poss[a[i]].second = i;
            else poss[a[i]].first = i;
        }
        for (int i = 1;i <= n;++i) {
            a3s.push_back({ i,poss[i].first,poss[i].second });
            // std::cout << poss[a[i]].first << " " << poss[a[i]].second << '\n';
        }
    }
    std::sort(a3s.begin(), a3s.end(), [&](a3 a, a3 b) {
        return a[2] - a[1] < b[2] - b[1];
        });
    auto work = [&](i64 l, i64 r, i64 x) {
        // if (x == 1)std::cout << l << ' ' << r << ' ';
        std::vector<i64> dp(r + 1);
        for (int al = l;al <= r;++al) {
            int cur = a[al];
            if (al == poss[cur].first) {
                int ar = poss[cur].second;
                if (ar <= r) {
                    i64 add = cur;
                    dp[ar] = std::max(dp[ar], (al == 0 ? 0 : dp[al - 1]) + res[cur]);
                }
            }
            dp[al] = std::max(dp[al], (al == 0 ? 0 : dp[al - 1]) + x);
        }
        return dp[r] + 2 * x;
        };
    for (int i = 0;i < n;++i) {
        // std::cout << a3s[i][1] + 1 << ' ' << a3s[i][2] - 1 << '\n';
        res[a3s[i][0]] = work(a3s[i][1] + 1, a3s[i][2] - 1, a3s[i][0]);
        // std::cout << a3s[i][0] << ' ' << res[a3s[i][0]] << '\n';
    }
    std::cout << work(0, 2 * n - 1, 0);
    return 0;
}