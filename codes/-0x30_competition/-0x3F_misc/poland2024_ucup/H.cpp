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
    std::vector<double> p(n), dp(n);
    for (auto& x : p)std::cin >> x;
    double max = 0;
    for (int i = n - 1;i >= 0;--i) {
        dp[i] = p[i] * i;
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    std::cout << std::fixed;
    std::cout.precision(14);
    int t = 1;
    while (t--) {
        solve();
        std::cout << '\n';
    }
    return 0;
}