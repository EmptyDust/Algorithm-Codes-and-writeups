#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10;
int nums[MAXN], n;
using pt = std::pair<int, int>;

void solve() {
    int k;
    std::cin >> n >> k;k--;
    for (int i = 0;i < n;++i)std::cin >> nums[i];
    int me = nums[k];
    int ans = 0, j = n + 1;
    std::swap(nums[0], nums[k]);
    for (int i = 1;i < n;++i) {
        if (me > nums[i])ans++;
        else {
            j = i;
            break;
        }
    }
    std::swap(nums[0], nums[k]);
    std::swap(nums[j], nums[k]);
    for (int i = 0;i < j;++i) {
        if (nums[i] > nums[j]) {
            std::cout << ans;
            return;
        }
    }
    int cnt = (j > 0);
    for (int i = j + 1;i < n;++i) {
        if (nums[j] > nums[i])cnt++;
        else break;
    }
    ans = std::max(ans, cnt);
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