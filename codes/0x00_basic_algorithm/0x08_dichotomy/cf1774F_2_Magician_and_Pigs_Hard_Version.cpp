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

void solve() {
    int n;std::cin >> n;
    std::vector<i64> op(n), info(n), pow2(n + 1, 1);
    for (int i = 1;i <= n;++i)
        pow2[i] = pow2[i - 1] * 2 % mod;
    i64 sum = 0;
    for (int i = 0;i < n;++i) {
        std::cin >> op[i];
        if (op[i] == 1)
            std::cin >> info[i];
        else if (op[i] == 2) {
            std::cin >> info[i];
            sum += info[i];
            if (sum > 1e9)sum = 1e9;
        }
        else if (op[i] == 3) {
            info[i] = sum;
            sum = sum * 2;
            if (sum > 1e9)sum = 1e9;
        }
    }
    sum = 0;
    i64 ans = 0, pow = 1;
    std::vector<i64> sums;
    for (int i = n - 1;i >= 0;--i) {
        if (op[i] == 1) {
            if (info[i] <= sum)continue;
            info[i] -= sum;
            ans = (ans + pow) % mod;
            int sz = sums.size();
            for (int j = 0;j < sz;++j) {
                // std::cout << sums[j] << " ";
                if (info[i] > sums[j]) {
                    ans = (ans + pow2[sz - 1 - j] * pow % mod) % mod;// 1ll << (sz - 1 - j);
                    info[i] -= sums[j];
                }
            }
            // std::cout << '\n';
        }
        else if (op[i] == 2) {
            sum += info[i];
            if (sum > 1e9)break;
        }
        else if (op[i] == 3) {
            if (info[i] == 0) {
                pow = pow * 2 % mod;
            }
            else if (info[i] != 1e9) {
                sums.push_back(info[i]);
            }
        }
    }
    std::cout << ans;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t = 1;//std::cin >> t;
    while (t--) {
        solve();
        std::cout << '\n';
    }
    return 0;
}