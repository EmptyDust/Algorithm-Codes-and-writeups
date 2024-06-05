#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
int nums[MAXN], n;
using pt = std::pair<int, int>;

void solve() {
    std::string s;std::cin >> s;
    std::vector<int> nums(1, 1);
    for (int i = 1;i < s.length();++i) {
        if (s[i] != s[i - 1]) {
            nums.push_back(1);
        }
        else nums.back()++;
    }
    if (nums.size() == 1) {
        std::cout << nums[0] / 2;
        return;
    }
    if (s.front() == s.back())nums[0] += nums.back(), nums.pop_back();
    bool f = false;
    int ans = 0;
    for (int x : nums) {
        if (x % 2 == 0)f = true;
        ans += x / 2;
    }
    std::cout << ans - f;
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