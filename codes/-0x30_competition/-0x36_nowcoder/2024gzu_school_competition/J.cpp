#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10;
int n, m;
using pt = std::pair<int, int>;

bool check(std::vector<std::vector<int>>& dp) {
    //检查是否通路
    if (!dp[0][0])return false;
    std::vector<std::vector<bool>> vis(n, std::vector<bool>(m, 0));
    std::queue<pt> q;
    q.push({ 0,0 });
    auto valid = [&](int x, int y) {
        return (n > x && x >= 0 && m > y && y >= 0 && dp[x][y] && !vis[x][y]);
        };

    pt p[4] = { {1,0},{0,1},{-1,0},{0,-1} };
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        if (x == n - 1 && y == m - 1)return true;
        for (int i = 0;i < 4;++i) {
            if (valid(x + p[i].first, y + p[i].second)) {
                vis[x + p[i].first][y + p[i].second] = true;
                q.push({ x + p[i].first, y + p[i].second });
            }
        }
    }
    return false;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n >> m;
    std::vector<std::vector<int>> nums(n, std::vector<int>(m, 1)), dp(nums);
    for (int i = 0;i < n;++i)for (int j = 0;j < m;++j)std::cin >> nums[i][j];
    int res = 0;
    for (int s = 30;s >= 0;--s) {
        std::vector<std::vector<int>> tmp(dp);
        for (int i = 0;i < n;++i)for (int j = 0;j < m;++j)if (tmp[i][j]) {
            tmp[i][j] = nums[i][j] & (1 << s);
        }
        if (check(tmp)) {
            dp = tmp;
            res |= 1 << s;
        }
    }
    std::cout << res;
    return 0;
}