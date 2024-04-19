#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, mod = 998244353;
using pt = std::pair<int, int>;
/*
signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int n;std::cin >> n;
    std::vector<int> nums(n);
    for (int i = 0;i < n;++i)std::cin >> nums[i];
    std::sort(nums.begin(), nums.end());
    std::vector<i64> f(5001);f[0] = 1;
    i64 odd = 0, even = 0, sum = 0, ans = 0;//>5000
    for (int i = 0;i < n;++i) {
        if (nums[i] & 1) {
            ans += (sum + nums[i] * (odd + even) - even) / 2 + even;
            sum += nums[i] * (odd + even);
            auto _even = even;
            even += odd;
            odd += _even;
        }
        else {
            ans += (sum + nums[i] * (odd + even) - odd) / 2 + odd;
            sum += nums[i] * (odd + even);
            even += even;
            odd += odd;
        }
        for (int x = 5000;x >= 0;--x)if (f[x]) {
            if (x <= nums[i])
                ans += nums[i] * f[x];
            else
                ans += ((x + nums[i]) / 2 + (x + nums[i]) % 2) * f[x];
            if (x + nums[i] > 5000) {
                sum += (x + nums[i]) * f[x];
                ((x + nums[i]) % 2 ? odd : even) += f[x];
            }
            else {
                f[x + nums[i]] += f[x];
            }
        }
    }
    std::cout << ans;
    return 0;
}
*/


i64 qpow(i64 x, i64 p) {
    i64 ret = 1;
    while (p) {
        if (p & 1)ret = ret * x % mod;
        p >>= 1;
        x = x * x % mod;
    }
    return ret;
}

#define inv(x) qpow(x,mod-2)

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int n;std::cin >> n;
    std::vector<i64> nums(n);
    for (int i = 0;i < n;++i)std::cin >> nums[i];
    std::sort(nums.begin(), nums.end());
    std::vector<i64> f(5001);f[0] = 1;
    i64 odd = 0, even = 0, sum = 0, ans = 0;//>5000
    for (int i = 0;i < n;++i) {
        if (nums[i] & 1) {
            sum = (sum + nums[i] * (odd + even) % mod) % mod;
            ans = ((ans + ((sum - even) % mod + mod) % mod * inv(2) % mod) % mod + even) % mod;
            auto _even = even;
            even = (even + odd) % mod;
            odd = (odd + _even) % mod;
        }
        else {
            sum = (sum + nums[i] * (odd + even) % mod) % mod;
            ans = ((ans + ((sum - odd) % mod + mod) % mod * inv(2)) % mod + odd) % mod;
            even = even * 2 % mod;
            odd = odd * 2 % mod;
        }
        for (i64 x = 5000;x >= 0;--x)if (f[x]) {
            if (x <= nums[i])
                ans = (ans + nums[i] * f[x] % mod) % mod;
            else
                ans = (ans + ((x + nums[i]) / 2 % mod + (x + nums[i]) % 2) * f[x] % mod) % mod;
            if (x + nums[i] > 5000) {
                sum = (sum + (x + nums[i]) * f[x] % mod) % mod;
                ((x + nums[i]) % 2 ? odd : even) += f[x];
            }
            else {
                f[x + nums[i]] = (f[x + nums[i]] + f[x]) % mod;
            }
        }
    }
    std::cout << ans;
    return 0;
}
