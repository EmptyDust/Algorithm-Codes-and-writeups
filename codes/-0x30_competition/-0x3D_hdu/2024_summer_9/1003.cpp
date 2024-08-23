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

// a b c d
//
// std::vector<i64> res;

// void dfs(std::vector<i64>& a, i64 x) {
//     int n = a.size();
//     if (n == 1) {
//         res.push_back(x);
//         return;
//     }
//     for (int i = 0, j = n - 1;i < j;++i, --j) {
//         std::vector<i64> na, ma;
//         for (int k = 0;k < n;++k) {
//             if (k == i)na.push_back(a[i] + a[j]);
//             else if (k == j)ma.push_back(a[i] + a[j]);
//             else {
//                 na.push_back(a[k]);
//                 ma.push_back(a[k]);
//             }
//         }
//         // std::cout << n << '\n';
//         // for (int x : na)std::cout << x << " ";std::cout << "\n";
//         dfs(ma, x + a[i] * a[j] * (a[i] + a[j]));
//         dfs(na, x + a[i] * a[j] * (a[i] + a[j]));
//     }
// }

void solve() {
    int n;std::cin >> n;
    std::vector<i64> a(n);
    for (auto& x : a)std::cin >> x;
    // dfs(a, 0);
    // std::cout << res.back() << ' ';
    i64 ans = 0;
    for (int i = n - 1;i >= 1;--i) {
        ans += a[0] * a[i] % mod * (a[0] + a[i]) % mod;
        ans %= mod;
        a[0] += a[i];
        a[0] %= mod;
    }
    std::cout << ans;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t = 1;std::cin >> t;
    while (t--) {
        solve();
        std::cout << '\n';
    }
    return 0;
}