#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<i64, i64>;

void solve() {
    int n, l, r;std::cin >> n >> l >> r;
    std::vector<i64> nums(n + 1), pre(n + 1), f(n + 1);
    for (int i = 1;i <= n;++i)std::cin >> nums[i];
    for (int i = 1;i <= n;++i)pre[i] = pre[i - 1] + nums[i];
    std::deque<pii> dq;
    for (int i = 1, pl = 0, pr = 0;i <= n;++i) {
        while (pr < i && pre[i] - pre[pr] >= l) {
            while (dq.size() && dq.back().first < f[pr])dq.pop_back();
            dq.push_back({ f[pr],pr });
            pr++;
        }
        while (pl < i && pre[i] - pre[pl] > r) {
            if (dq.front().second == pl)dq.pop_front();
            pl++;
        }
        if (dq.size())f[i] = dq.front().first + 1;
        f[i] = std::max(f[i], f[i - 1]);
    }
    std::cout << f.back();
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