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
    std::vector<int> v(1 << n), p;
    for (int i = 1;i < (1 << n);++i)std::cin >> v[i];
    std::vector<bool> ok(1 << n, 1);
    for (int s = 0;s < (1 << n);++s) {
        // std::cout << s << '\n';
        for (int t = 1;t < (1 << n);++t) {
            // std::cout << (s & t) << ' ' << (std::__popcount(s & t)) << "\n";
            if (!((1 << std::__popcount(s & t)) & v[t])) {
                ok[s] = false;
                break;
            }
        }
    }
    std::cout << std::count(ok.begin(), ok.end(), 1) << "\n";
    for (int s = 0;s < (1 << n);++s)
        if (ok[s])
            std::cout << s << '\n';
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}