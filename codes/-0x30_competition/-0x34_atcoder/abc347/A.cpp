#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10;
int nums[MAXN], n;
using pt = std::pair<int, int>;

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    std::vector<int> ans;
    int k;
    std::cin >> n >> k;
    for (int i = 0;i < n;++i)std::cin >> nums[i];
    for (int i = 0;i < n;++i)if (nums[i] % k == 0)ans.push_back(nums[i] / k);
    for (int num : ans)std::cout << num << ' ';
    return 0;
}