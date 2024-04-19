#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e3 + 10;
int nums[MAXN][MAXN], n, k;
std::vector<int> dp[MAXN];
using pt = std::pair<int, int>;

void solve() {
    std::cin >> n >> k;
    for (int i = 1;i <= n;++i)for (int j = i;j <= n;++j)
        std::cin >> nums[i][j];
    for (int i = 0;i <= n;++i)dp[i].clear();
    dp[0] = { 0 };
    for (int i = 1;i <= n;++i) {
        std::priority_queue<std::array<int, 3>> pq;
        pq.push({ dp[i - 1][0],i - 1,0 });
        for (int j = i - 2;j >= -1;--j) {
            pq.push({ (j < 0 ? 0 : dp[j][0]) + nums[j + 2][i], j, 0 });
        }
        while (pq.size() && dp[i].size() < k) {
            auto [val, j, num] = pq.top();pq.pop();
            dp[i].push_back(val);
            if (j < 0 || num + 1 == dp[j].size())continue;
            if (j == i - 1)
                pq.push({ dp[i - 1][num + 1],i - 1,num + 1 });
            else
                pq.push({ dp[j][num + 1] + nums[j + 2][i],j,num + 1 });
        }
    }
    for (int num : dp[n])
        std::cout << num << ' ';
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