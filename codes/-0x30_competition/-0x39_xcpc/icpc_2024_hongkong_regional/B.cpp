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
const int mod = 998244353;

void solve() {
    int n, m;std::cin >> n >> m;
    std::vector<a2> info(n);
    for (auto& [a, b] : info)std::cin >> a;
    for (auto& [a, b] : info)std::cin >> b;
    std::vector<i64> c(n), dpc(n, 1);
    for (auto& x : c)std::cin >> x;
    for (int i = n - 2;i >= 0;--i)
        c[i] = std::min(c[i], c[i + 1]);
    for (int i = 1;i < n;++i) {
        for (int j = 0;j < i;++j) {
            int k = i - j;
            if (c[i] > c[j] + c[k]) {
                c[i] = c[j] + c[k];
                dpc[i] = dpc[j] * dpc[k] % mod;
            }
            else if (c[i] == c[j] + c[k]) {
                dpc[i] = (dpc[i] + dpc[j] * dpc[k] % mod) % mod;
            }
        }
    }
    
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