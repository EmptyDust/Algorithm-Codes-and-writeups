#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<int, int>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
// const int mod = 1e9 + 7;
const int mod = 998244353;

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

void solve() {
    i64 n, k;std::cin >> n >> k;
    std::vector<int> a(n);
    for (int& x : a)std::cin >> x;
    i64 ans = 1;
    auto cal = [&](int l, int len, int r) {
        if (!len)return;
        // std::cout << l << " " << len << ' ' << r << ' ' << ans << '\n';
        if (l == -1 && r == -1) {
            ans = ans * k % mod * qpow(k - 1, len - 1) % mod;
            return;
        }
        if (l == -1 || r == -1) {
            ans = ans * qpow(k - 1, len) % mod;
            return;
        }
        if (a[l] == a[r]) {
            std::vector dp(2, std::vector<int>(len, 0));
            dp[0][0] = 0;
            dp[1][0] = k - 1;
            for (int i = 1;i < len;++i) {
                dp[0][i] = dp[1][i - 1];
                dp[1][i] = (dp[1][i - 1] * (k - 2) % mod + dp[0][i - 1] * (k - 1) % mod) % mod;
            }
            ans = ans * dp[1][len - 1] % mod;
        }
        else {
            // std::cout << ans << ' ';
            std::vector dp(2, std::vector<int>(len, 0));
            dp[0][0] = 1;
            dp[1][0] = k - 2;
            for (int i = 1;i < len;++i) {
                dp[0][i] = dp[1][i - 1];
                dp[1][i] = (dp[1][i - 1] * (k - 2) % mod + dp[0][i - 1] * (k - 1) % mod) % mod;
            }
            ans = ans * dp[1][len - 1] % mod;
        }
        };

    auto work = [&](int st) {
        int len = 0, l = -1;
        for (int i = st;i < n;i += 2) {
            if (i + 2 < n) {
                if (a[i] != -1 && a[i] == a[i + 2]) {
                    ans = 0;
                    return;
                }
            }
            if (a[i] == -1)len++;
            else {
                cal(l, len, i);
                len = 0;
                l = i;
            }
        }
        cal(l, len, -1);
        };
    work(0);
    // std::cout << ans << '\n';
    work(1);
    std::cout << ans;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t = 1;
    while (t--) {
        solve();
        std::cout << '\n';
    }
    return 0;
}