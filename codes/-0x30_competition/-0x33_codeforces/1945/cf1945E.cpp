#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10;
int nums[MAXN], n;
using pt = std::pair<int, int>;

void solve() {
    int n, x;
    std::cin >> n >> x;
    int ta;
    for (int i = 1;i <= n;++i) {
        std::cin >> nums[i];
        if (nums[i] == x)ta = i;
    }
    int l = 1, r = n + 1;
    while (l + 1 < r) {
        int mid = l + r >> 1;
        if (nums[mid] <= x)l = mid;
        else r = mid;
    }
    if (l == ta) {
        std::cout << 0;
        return;
    }
    std::cout << 1 << '\n';
    std::cout << l << ' ' << ta;
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