#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<int, int>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
// const int mod = 1e9 + 7;
const int mod = 998244353;

// ax - ay >= bx + by
// ax - bx >= ay + by

void solve() {
    int n;std::cin >> n;
    std::vector<int> pos(2 * n);
    std::vector<pii> info(n);
    for (int i = 0;i < n;++i) {
        int a, b;std::cin >> a >> b;
        info[i].first = a - b;
        info[i].second = a + b;
        pos[i * 2] = a - b;
        pos[i * 2 + 1] = a + b;
    }
    pos.push_back(-inf - 100);
    ranges::sort(pos);
    pos.erase(std::unique(pos.begin(), pos.end()), pos.end());
    std::unordered_map<int, int> mp;
    for (int i = 0;i < pos.size();++i)mp[pos[i]] = i;
    ranges::sort(info, [&](pii a, pii b) {
        return a.second < b.second;
        });
    std::vector<int> dp(pos.size());
    for (int i = 1, j = 0;i < pos.size();++i) {
        while (j < info.size() && mp[info[j].second] == i) {
            dp[i] = std::max(dp[i], dp[mp[info[j].first]] + 1);
            j++;
        }
        dp[i] = std::max(dp[i], dp[i - 1]);
    }
    // for (int x : pos)std::cout << x << ' ';std::cout << '\n';
    // for (int x : dp)std::cout << x << ' ';std::cout << '\n';
    std::cout << dp.back();
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