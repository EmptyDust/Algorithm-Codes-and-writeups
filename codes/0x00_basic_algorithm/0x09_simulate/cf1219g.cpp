#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pt = std::pair<int, int>;

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<i64>> map(n, std::vector<i64>(m));
    for (auto& vt : map)for (auto& num : vt)std::cin >> num;
    i64 ans = 0;
    {
        std::vector<i64> sums(n);
        for (int i = 0;i < n;++i)for (int j = 0;j < m;++j) {
            sums[i] += map[i][j];
        }
        std::vector<i64> maxs(4, 0);
        for (int i = 0;i < n;++i) {
            auto cur = sums[i];
            for (auto& x : maxs)if (cur > x)std::swap(cur, x);
        }
        ans = std::max(ans, std::accumulate(maxs.begin(), maxs.end(), (i64)0));
    }
    {
        std::vector<i64> sums(m);
        for (int i = 0;i < n;++i)for (int j = 0;j < m;++j) {
            sums[j] += map[i][j];
        }
        std::vector<i64> maxs(4, 0);
        for (int i = 0;i < m;++i) {
            auto cur = sums[i];
            for (auto& x : maxs)if (cur > x)std::swap(cur, x);
        }
        ans = std::max(ans, std::accumulate(maxs.begin(), maxs.end(), (i64)0));
    }
    {
        std::vector<i64> cur(m), cur2(n);
        for (int i = 0;i < n;++i)for (int j = 0;j < m;++j) {
            cur[j] += map[i][j];
            cur2[i] += map[i][j];
        }
        for (int a = 0;a < n;++a) {
            std::vector<i64> maxs(3, 0);
            for (int i = 0;i < m;++i) {
                auto curnum = cur[i] - map[a][i];
                for (auto& x : maxs)if (curnum > x)std::swap(curnum, x);
            }
            ans = std::max(ans, cur2[a] + std::accumulate(maxs.begin(), maxs.end(), (i64)0));
        }
    }
    {
        std::vector<i64> cur(n), cur2(m);
        for (int i = 0;i < n;++i)for (int j = 0;j < m;++j) {
            cur2[j] += map[i][j];
            cur[i] += map[i][j];
        }
        for (int a = 0;a < m;++a) {
            std::vector<i64> maxs(3, 0);
            for (int i = 0;i < n;++i) {
                auto curnum = cur[i] - map[i][a];
                for (auto& x : maxs)if (curnum > x)std::swap(curnum, x);
            }
            ans = std::max(ans, cur2[a] + std::accumulate(maxs.begin(), maxs.end(), (i64)0));
        }
    }
    if (n < m) {
        std::vector<i64> cur(m), cur2(n);
        for (int i = 0;i < n;++i)for (int j = 0;j < m;++j) {
            cur[j] += map[i][j];
            cur2[i] += map[i][j];
        }
        for (int a = 0;a < n;++a)for (int b = 0;b < n;++b)if (a != b) {
            i64 res1 = 0, res2 = 0;
            for (int i = 0;i < m;++i) {
                auto x = cur[i] - map[a][i] - map[b][i];
                if (x > res1) {
                    res2 = res1;
                    res1 = x;
                }
                else if (x > res2)
                    res2 = x;
            }
            ans = std::max(ans, res1 + res2 + cur2[a] + cur2[b]);
        }
    }
    else {
        std::vector<i64> cur(n), cur2(m);
        for (int i = 0;i < n;++i)for (int j = 0;j < m;++j) {
            cur2[j] += map[i][j];
            cur[i] += map[i][j];
        }
        for (int a = 0;a < m;++a)for (int b = 0;b < m;++b)if (a != b) {
            i64 res1 = 0, res2 = 0;
            for (int i = 0;i < n;++i) {
                auto x = cur[i] - map[i][a] - map[i][b];
                if (x > res1) {
                    res2 = res1;
                    res1 = x;
                }
                else if (x > res2)
                    res2 = x;
            }
            ans = std::max(ans, res1 + res2 + cur2[a] + cur2[b]);
        }
    }
    std::cout << ans;
    return 0;
}