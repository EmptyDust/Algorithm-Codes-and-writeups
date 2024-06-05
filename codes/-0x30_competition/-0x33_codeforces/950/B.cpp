#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pt = std::pair<int, int>;

void solve() {
    int n, f, k;std::cin >> n >> f >> k;
    std::vector<int> nums(n);
    for (int& x : nums)std::cin >> x;
    int fav = nums[f - 1];
    std::sort(nums.begin(), nums.end(), std::greater<int>());
    if (nums[k - 1] == fav && k != n && nums[k] == fav)std::cout << "MAYBE";
    else if (nums[k - 1] > fav)std::cout << "NO";
    else std::cout << "YES";
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