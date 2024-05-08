#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
int nums[MAXN], n;
using pt = std::pair<int, int>;

void solve() {
    std::cin >> n;
    for (int i = 0;i < n;++i)std::cin >> nums[i];
    std::map<int, int> mp;
    int ans = 0;
    for (int i = 0, cur = -1;i < n;++i) {
        if (!mp.count(nums[i])) {
            cur = i;
            mp[nums[i]] = i;
        }
        else if (mp[nums[i]] >= cur) {
            ans++;
            cur = i;
        }
        else {
            cur = std::max(cur, i);
            mp[nums[i]] = i;
        }
        std::cout << cur << ' ';
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