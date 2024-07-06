#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 1e6 + 10;
int nums[MAXN];

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int n;cin >> n;
    for (int i = 0;i < n;++i)cin >> nums[i];
    sort(nums, nums + n);
    for (int i = 0;i < n;++i)if (nums[i] != nums[0]) {
        cout << nums[i];
        break;
    }
    return 0;
}