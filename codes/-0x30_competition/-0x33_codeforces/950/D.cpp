#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pt = std::pair<int, int>;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> nums(n);
    for (int& x : nums)std::cin >> x;
    int gcdn = n - 1;
    std::vector<int> gcds(gcdn);
    for (int i = 0;i < n - 1;++i)gcds[i] = std::__gcd(nums[i], nums[i + 1]);
    std::vector<bool> pre(n, true), suf(n, true);
    for (int i = 2;i < n - 1;++i)pre[i] = pre[i - 1] & (gcds[i - 1] >= gcds[i - 2]);
    for (int i = n - 3;i >= 0;--i)suf[i] = suf[i + 1] & (gcds[i] <= gcds[i + 1]);
    if (suf[1]) {
        std::cout << "YES";
        return;
    }
    if (pre[n - 2]) {
        std::cout << "YES";
        return;
    }
    for (int i = 1;i < n - 1;++i) if (suf[i + 1] && pre[i - 1]) {
        int gcd = std::__gcd(nums[i - 1], nums[i + 1]);
        if ((i >= 2 ? (gcds[i - 2] <= gcd) : 1) && (i < n - 2 ? gcd <= gcds[i + 1] : 1)) {
            std::cout << "YES";
            return;
        }
    }
    std::cout << "NO";
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