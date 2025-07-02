#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using u128 = unsigned __int128;

using a2 = std::array<int, 2>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
// const int mod = 1e9 + 7;
const int mod = 998244353;

// long double dp[8001][401][4001];

void solve() {
    int n, m;double p;std::cin >> n >> m >> p;p /= 100;
    std::vector<int> a(n);
    for (auto& x : a)std::cin >> x;
    int min = ranges::min(a);
    int sum = 0;
    for (auto& x : a)sum += x - min;
    std::vector dp(sum + 1, std::vector<std::vector<long double>>(min + 1, std::vector<long double>(m + 1, -1)));
    auto dfs = [&](auto&& self, int sum, int min, int time) ->long double {
        if (sum < 0 || min < 0 || time < 0)return 0;
        if (sum == 0 && min == 0)return 1;
        if (dp[sum][min][time] != -1)return dp[sum][min][time];
        auto& cur = dp[sum][min][time];
        if (time < sum)return cur = 0;
        cur = p * std::max(self(self, sum, min, time - 1), self(self, sum, min - 1, time - 1))
            + (1 - p) * std::max(self(self, sum, min, time - 1), self(self, sum - 1, min, time - 1));
        std::cout << sum << ' ' << min << ' ' << time << ' ' << cur << '\n';
        return cur;
        };
    std::cout << dfs(dfs, sum, min, m);

}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    std::cout << std::fixed << std::setprecision(10);
    int t;std::cin >> t;
    while (t--) {
        solve();
        std::cout << '\n';
    }
    return 0;
}