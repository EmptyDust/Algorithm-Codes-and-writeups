#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
int nums[MAXN], n;
using pt = std::pair<int, int>;
using a3 = std::array<int, 3>;

void solve() {
    std::cin >> n;
    for (int i = 0;i < n;++i)
        std::cin >> nums[i];
    std::map<pt, int> mp1, mp2, mp3;
    std::map<a3, int> mp;
    i64 ans = 0;
    for (int i = 2;i < n;++i) {
        ans += mp1[{nums[i - 2], nums[i - 1]}] - mp[{nums[i - 2], nums[i - 1], nums[i]}];
        ans += mp2[{nums[i - 2], nums[i]}] - mp[{nums[i - 2], nums[i - 1], nums[i]}];
        ans += mp3[{nums[i - 1], nums[i]}] - mp[{nums[i - 2], nums[i - 1], nums[i]}];
        mp1[{nums[i - 2], nums[i - 1]}]++;
        mp2[{nums[i - 2], nums[i]}]++;
        mp3[{nums[i - 1], nums[i]}]++;
        mp[{nums[i - 2], nums[i - 1], nums[i]}]++;
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