#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    i64 n, m, k, d, num;std::cin >> n >> m >> k >> d;
    std::vector<i64> ans(n);
    for (int j = 0;j < n;++j) {
        std::deque<int> q;q.push_back(0);
        std::vector<i64> f(m);f[0] = 1;
        std::cin >> num;
        for (int i = 1;i < m;++i) {
            while (!q.empty() && q.front() < i - d - 1)q.pop_front();
            std::cin >> num;
            f[i] = num + 1 + f[q.front()];
            while (!q.empty() && f[q.back()] >= f[i])q.pop_back();
            q.push_back(i);
        }
        ans[j] = f[m - 1];
    }
    i64 tmp = 0, res = 1e12, cnt = 0;
    for (int i = 0;i < n;++i) {
        tmp += ans[i];cnt++;
        if (cnt == k) {
            res = std::min(res, tmp);
            tmp -= ans[i - k + 1];
            cnt--;
        }
    }
    std::cout << res;
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