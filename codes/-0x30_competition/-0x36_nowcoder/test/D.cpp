#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10;
int nums[MAXN], n;
using pt = std::pair<int, int>;

void solve() {
    int n, m;
    std::cin >> n >> m;
    for (int i = 0;i < m;++i)std::cin >> nums[i];
    std::vector<pt> dp(n, { 1,1 });
    for (int i = 0;i < m - 1;++i) {
        std::vector<pt> tmp(n, { 0,0 });
        if (nums[i + 1] == 1) {
            int pre = -1;
            for (int j = 0;j < n;++j) {
                if (dp[j].first) {
                    if (j + nums[i] - 1 < n) {
                        for (int k = std::max(j, pre);k < j + nums[i];++k) {
                            tmp[k].first = 1;
                            tmp[k].second = 1;
                        }
                        pre = j + nums[i];
                    }
                    else break;
                }
            }
            pre = n;
            for (int j = n - 1;~j;--j) {
                if (dp[j].second) {
                    if (j - nums[i] + 1 >= 0) {
                        for (int k = std::min(pre, j);k > j - nums[i];--k) {
                            tmp[k].first = 1;
                            tmp[k].second = 1;
                        }
                        pre = j - nums[i];
                    }
                    else break;
                }
            }
            i++;
            dp = tmp;
            continue;
        }
        for (int j = 0;j < n;++j) {
            if (dp[j].first) {
                if (j + nums[i] - 1 < n) {
                    tmp[j].second = 1;
                    tmp[j + nums[i] - 1].first = 1;
                }
            }
            if (dp[j].second) {
                if (j - nums[i] + 1 >= 0) {
                    tmp[j].first = 1;
                    tmp[j - nums[i] + 1].second = 1;
                }
            }
        }
        dp = tmp;
    }
    int ans = 0;
    for (pt a : dp) {
        ans += (a.first || a.second);
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