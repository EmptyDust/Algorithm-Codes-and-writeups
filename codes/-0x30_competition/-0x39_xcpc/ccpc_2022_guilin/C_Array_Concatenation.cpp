#include<bits/stdc++.h>
using i64 = long long;

#define int long long

using i128 = __int128;

const int mod = 1e9 + 7;

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

void solve(){
    int n, m;std::cin >> n >> m;
    std::vector<i64> a(n);
    for (auto& num : a) std::cin >> num;

    std::vector<i64> vt1(2 * n), vt2(2 * n);
    for (int i = 0;i < n;++i){
        vt1[i] = vt1[i + n] = a[i];
        vt2[n - i - 1] = vt2[n + i] = a[i];
    }

    std::vector<i64> pow2(m + 1);pow2[0] = 1;
    for (int i = 1;i <= m;++i)pow2[i] = pow2[i - 1] * 2 % mod;

    i64 inv2 = inv(2);

    i64 ans = 0;
    {
        i64 sum = 0;
        for (int i = 0;i < 2 * n;++i){
            sum = (sum + vt1[i] * pow2[m - 1] % mod * (pow2[m] * n % mod - i + 2 * n - i) % mod * inv2 % mod) % mod;
        }
        sum = (sum % mod + mod) % mod;
        ans = std::max(ans, sum);
    }
    {
        i64 sum = 0;
        for (int i = 0;i < 2 * n;++i){
            sum = (sum + vt2[i] * pow2[m - 1] % mod * (pow2[m] * n % mod - i + 2 * n - i) % mod * inv2 % mod) % mod;
        }
        sum = (sum % mod + mod) % mod;
        ans = std::max(ans, sum);
    }

    std::cout << ans;
}

signed main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t = 1;
    while (t--){
        solve();
        std::cout << '\n';
    }
    return 0;
}