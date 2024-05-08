#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
int nums[MAXN], n;
using pt = std::pair<int, int>;

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    i64 n, k, s;std::cin >> n >> k >> s;
    if (k == 1) {
        if (n == 1) {
            std::cout << "YES\n1";
        }
        else std::cout << "NO";
        return 0;
    }
    std::vector<int> nums(n + 2);
    for (int i = 1;i <= std::min(k, n);++i) {
        if (nums[i - 1] != 1 && nums[i + 1] != 1)nums[i] = 1;
        else if (nums[i - 1] != 2 && nums[i + 1] != 2)nums[i] = 2;
        else nums[i] = 3;
        for (int j = i + k;j <= n;j += k) {
            nums[j] = nums[i];
        }
    }
    i64 sum = std::accumulate(nums.begin() + 1, nums.end() - 1, (i64)0);
    if (sum > s) {
        std::cout << "NO";
        return 0;
    }
    std::cout << "YES\n";
    for (int i = 1;i <= n;++i)std::cout << nums[i] << ' ';
    return 0;
}