#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
int nums[MAXN], n;
using pt = std::pair<int, int>;
//2 2 12 12 122 22
signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n;
    std::string s;std::cin >> s;
    i64 ans = 0, x = 0;
    for (int i = 0;i < n;++i) {
        int num = s[i] - '0';
        if (num % 2 == 0)ans = (ans + x + 1) % mod;
        x = x * 2 % mod;
        if (num)x++;
    }
    ans %= mod;
    std::cout << ans;
    return 0;
}