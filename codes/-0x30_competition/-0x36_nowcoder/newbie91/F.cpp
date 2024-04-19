#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
int nums[MAXN], n;
using pt = std::pair<int, int>;

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int n;std::cin >> n;
    std::vector<int> nums(n + 1);
    for (int i = 1;i <= n;++i)std::cin >> nums[i];
    i64 ans = 0;
    for (int s = 30;s >= 0;--s) {
        std::vector<i64> pre(n + 1), suf(n + 2);
        for (int i = 1;i <= n;++i) {
            pre[i] = pre[i - 1];
            if (nums[i] >> s & 1)pre[i] += i;
        }
        for (int i = n;i;--i) {
            suf[i] = suf[i + 1];
            if (nums[i] >> s & 1)suf[i] += n - i + 1;
        }
        for (int i = n;i;--i)if (!(nums[i] >> s & 1)) {
            i64 ad = (pre[i] * (n - i + 1) % mod + suf[i] * i % mod) % mod * (1 << s) % mod;
            ans = (ans + ad) % mod;
        }
    }
    ans = (ans * 2) % mod;
    std::cout << ans;
    return 0;
}