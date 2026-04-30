#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10;
int nums[MAXN], n;
using pt = std::pair<int, int>;

void solve() {
    int n, c, d;std::cin >> n >> c >> d;
    std::vector<int> nums(n * n);
    for (int& num : nums)std::cin >> num;
    std::sort(nums.begin(), nums.end());
    std::vector<int> res(n * n);
    res[0] = nums[0];
    for (int i = 1;i < n * n;++i) {
        if (i % n == 0) {
            res[i] = res[i - n] + c;
        }
        else res[i] = res[i - 1] + d;
    }
    std::sort(res.begin(), res.end());
    std::cout << (res == nums ? "Yes" : "No");
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