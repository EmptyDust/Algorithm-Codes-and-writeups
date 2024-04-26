#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pt = std::pair<int, int>;

void solve() {
    int n;std::cin >> n;
    std::vector<int> nums(n + 1), ss(n + 1);
    for (int i = 1;i <= n;++i) std::cin >> nums[i];
    for (int i = 1;i <= n;++i) ss[i] = ss[i - 1] ^ nums[i];
    int mask = 0;
    i64 ans = 0;
    for (int s = 30;s >= 0;s--) {
        std::vector<i64> even(n + 1), odd(n + 1);even[0]++;
        for (int i = 1;i <= n;++i) {
            even[i] = even[i - 1];
            odd[i] = odd[i - 1];
            if (ss[i] >> s & 1)
                odd[i]++;
            else even[i]++;
        }
        for (int i = 1;i <= n;++i)if ((nums[i] >> s & 1) && (mask & nums[i]) == 0) {
            ans += even[i - 1] * (even[n] - even[i - 1]) + odd[i - 1] * (odd[n] - odd[i - 1]);
        }
        mask += 1 << s;
    }
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