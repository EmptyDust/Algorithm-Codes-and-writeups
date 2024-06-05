#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
constexpr int N = 1e7, MAXN = 1e7 + 10, mod = 998244353;
using pt = pair<int, int>;
bool isp[MAXN];
i64 inv_num[MAXN];

i64 qpow(i64 x, int p) {
    i64 ret = 1;
    while (p) {
        if (p & 1)ret = ret * x % mod;
        x = x * x % mod;
        p >>= 1;
    }
    return ret;
}

#define inv(x) qpow(x,mod-2)


signed main() {
    ios::sync_with_stdio(false);
    std::cin.tie(0), cout.tie(0);
    int n;cin >> n;
    for (int i = 1;i <= n;++i)inv_num[i] = 1;
    i64 res = 1;
    for (i64 i = 2;i <= n;++i) if (!isp[i]) {
        i64 inv = inv(i);
        for (i64 j = i;j <= n;j += i) {
            isp[j] = 1;
        }
        i64 x = 1;
        while (x <= n / i) {
            x *= i;
            for (i64 j = x;j <= n;j += x) {
                inv_num[j] = inv_num[j] * inv % mod;
            }
        }
        res = res * x % mod;
    }

    i64 ans = 0, sum = 0, cnt = 0;
    for (int i = 1;i <= n;++i) {
        i64 cur = res * inv_num[i] % mod;
        ans = ((ans + sum - cnt * cur % mod) % mod + mod) % mod;
        sum = (sum + cur) % mod;
        cnt++;
    }
    cout << ans;

    return 0;
}