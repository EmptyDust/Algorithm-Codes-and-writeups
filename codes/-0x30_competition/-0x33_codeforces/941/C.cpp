#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
int nums[MAXN], f[MAXN], n;
using pt = std::pair<int, int>;

void solve() {
    int n;std::cin >> n;
    for (int i = 1;i <= n;++i)std::cin >> nums[i];
    std::sort(nums + 1, nums + n + 1);
    for (int i = 1;i <= n;++i)f[i] = nums[i] - nums[i - 1];
    bool ff = true;
    for (int i = 1;i <= n;++i) {
        if (f[i] == 1)ff = !ff;
        if (f[i] > 1) {
            break;
        }
    }
    std::cout << (ff ? "Alice" : "Bob");
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