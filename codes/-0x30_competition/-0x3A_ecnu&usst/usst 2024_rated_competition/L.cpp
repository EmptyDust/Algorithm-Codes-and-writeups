#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;

void solve() {
    int n;std::cin >> n;
    std::vector<int> a(n);
    for (int& x : a)std::cin >> x;
    for (int i = 0;i < n;++i)a[i] -= i;
    std::map<int, int> mp;
    std::vector<int> nums[n];
    for (int i = 0;i < n;++i) {
        if (!mp.count(a[i])) {
            mp[a[i]] = i;
        }
        nums[mp[a[i]]].push_back(a[i] + i);
    }
    i64 ans = 0;
    for (int i = 0;i < n;++i)if (nums[i].size() > 1) {
        int sz = nums[i].size();
        for (int j = sz - 1;j > 0;j -= 2) {
            if (nums[i][j] + nums[i][j - 1] > 0)ans += nums[i][j] + nums[i][j - 1];
        }
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