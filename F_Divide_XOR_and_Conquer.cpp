#include <bits/stdc++.h>

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

void solve() {
    int n;std::cin >> n;
    std::vector<i64> a(n + 1);
    for (int i = 1;i <= n;++i)std::cin >> a[i];
    for (int i = 1;i <= n;++i)a[i] ^= a[i - 1];
    std::vector<std::vector<bool>> ok(n + 1, std::vector<bool>(n + 1));
    std::vector<i64> L0(n + 1);
    std::vector<i64> R0(n + 1);
    std::vector<i64> L1(n + 1);
    std::vector<i64> R1(n + 1);
    ok[0][n] = true;
    std::string ans;
    for (int i = 0;i < n;++i) {
        for (int j = n;j >= i + 1;j--) {
            if (a[j] & L1[i]) {
                ok[i][j] = true;
            }
            if ((~a[j]) & L0[i]) {
                ok[i][j] = true;
            }
            // if (i == 1 && j == 2)std::cout << ok[i][j] << " ";
            if (a[i] & R1[j]) {
                ok[i][j] = true;
            }
            if ((~a[i]) & R0[j]) {
                ok[i][j] = true;
            }
            if (j == i + 1) {
                ans += (ok[i][j] ? "1" : "0");
                continue;
            }
            if (!ok[i][j])continue;
            i64 x = a[i] ^ a[j];
            if (x == 0) {
                L0[i] = -1;
                L1[i] = -1;
                R0[j] = -1;
                R1[j] = -1;
            }
            else {
                // int b = 63 - std::__countl_zero(x);
                i64 bit = 1ll << std::__lg(x);
                if (a[i] & bit) {
                    L0[i] |= bit;
                    R1[j] |= bit;
                }
                else {
                    L1[i] |= bit;
                    R0[j] |= bit;
                }
            }
            // if (i == 0 && j == n)std::cout << L1[i] << ' ';
        }
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