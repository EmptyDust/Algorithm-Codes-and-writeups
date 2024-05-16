#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
int nums[MAXN], suf[MAXN], n;
using pt = std::pair<int, int>;

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n;
    for (int i = 0;i < n;++i)std::cin >> nums[i];
    suf[n] = inf;
    for (int i = n - 1;i >= 0;--i) {
        suf[i] = std::min(suf[i + 1], nums[i]);
    }
    int ans = 0;
    for (int i = 0, coin = 1;i < n;++i, ++coin) {
        while (coin >= suf[i]) {
            ans++;
            coin -= suf[i];
        }
    }
    std::cout << ans;
    return 0;
}