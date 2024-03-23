#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10;
int nums[MAXN], n;
using pt = std::pair<int, int>;

bool solve() {
    std::cin >> n;
    for (int i = 0;i < n;++i)std::cin >> nums[i];
    for (int i = 0;i < n - 2;++i) {
        nums[i + 1] -= 2 * nums[i];
        nums[i + 2] -= nums[i];
        if (nums[i + 1] < 0 || nums[i + 2] < 0)return false;
    }
    return nums[n - 1] == 0 && nums[n - 2] == 0;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t;std::cin >> t;
    while (t--) {
        std::cout << (solve() ? "Yes" : "No");
        std::cout << '\n';
    }
    return 0;
}