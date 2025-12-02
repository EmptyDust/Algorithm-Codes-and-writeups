#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using u128 = unsigned __int128;

using a2 = std::array<int, 2>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
// const int mod = 1e9 + 7;
// const int mod = 998244353;
const int mod = 1e6 + 3;

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

std::vector<i64> fact(mod), invf(mod);

void solve() {
    int n;std::cin >> n;
    std::vector<i64> a(n), b(n);
    for (auto& x : a) std::cin >> x;
    for (auto& x : b) std::cin >> x;
    i64 ans1 = 0, ans2 = 1;
    for (int t = 30;t >= 0;--t) {
        bool f = 1;
        i64 cnt = 0;
        for (int i = 0;i < n;++i) {
            if (b[i] / 2 < a[i]) {
                f = 0;
                break;
            }
            cnt += b[i] % 2;
        }
        if (!f) {
            i64 tmp = 1;
            cnt = 0;
            for (int i = 0;i < n;++i) {
                int c = b[i] - a[i];
                if (cnt + c < mod)
                    tmp = tmp * fact[cnt + c] % mod * invf[c] % mod * invf[cnt] % mod;  // comb(cnt + c, cnt)
                else tmp = 0;
                cnt += c;
            }
            ans2 = ans2 * tmp % mod;
        }
        else {
            for (int i = 0;i < n;++i) {
                b[i] = b[i] / 2;
            }
            ans1++;
            ans2 = ans2 * fact[cnt] % mod;
        }
        ans1 += cnt;
        if (!f) break;
    }
    std::cout << ans1 << ' ' << ans2;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    fact[0] = invf[0] = 1;
    for (int i = 1;i <= 1e6 + 2;++i) {
        fact[i] = fact[i - 1] * i % mod;
        invf[i] = invf[i - 1] * inv(i) % mod;
    }
    int t;std::cin >> t;
    while (t--) {
        solve();
        std::cout << '\n';
    }
    return 0;
}