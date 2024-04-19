#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10;
int nums[MAXN], n;
using pt = std::pair<int, int>;

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n;
    for (int i = 0;i < n;++i)std::cin >> nums[i];
    i64 ans = 0;
    for (int s = 30;s >= 0;--s) {
        i64 odd = 0, even = 1;
        bool f = false;
        for (int i = 0;i < n;++i) {
            if (nums[i] >> s & 1)f = !f;
            ans += (f ? even : odd) * (1 << s);
            f ? ++odd : ++even;
        }
    }
    std::cout << ans;
    return 0;
}
//000110011000
//000101010100