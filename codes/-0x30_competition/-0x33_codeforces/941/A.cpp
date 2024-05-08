#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
int nums[MAXN], n;
using pt = std::pair<int, int>;

void solve() {
    int n, k;std::cin >> n >> k;
    for (int i = 0;i < n;++i)std::cin >> nums[i];
    std::sort(nums, nums + n);
    bool f = false;
    for (int i = k - 1;i < n;++i) {
        bool ff = true;
        for (int j = i;j >= i - k + 1;--j)if (nums[j] != nums[i]) {
            ff = false;
            break;
        }
        if (ff) {
            f = true;
            break;
        }
    }
    if (f)std::cout << k - 1;
    else std::cout << n;
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