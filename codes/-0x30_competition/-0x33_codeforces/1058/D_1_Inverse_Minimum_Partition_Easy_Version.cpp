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
const i64 inf = 2e18;
// const int mod = 1e9 + 7;
const int mod = 998244353;

// 5 4 2 3 1 5 4 3 2 

// 3 4 5 6 10 15 20 21 42 43 67
// 1: last if cost <= 2 else new
// 1: maxcost = 2logA

// 2: maxPcost <= 3
// 1 2 4 5

const int MC = 3;

void solve() {
    int n;std::cin >> n;
    std::vector<i64> a(n);
    for (auto& x : a)std::cin >> x;
    std::vector<i64> b;
    for (auto x : a) {
        while (b.size() && b.back() >= x) b.pop_back();
        b.push_back(x);
    }
    int m = b.size();
    std::vector<i64> dp(m + 1, inf);
    dp[0] = 0;
    std::vector<int> p(MC + 1);
    for (int i = 0;i < m;++i) {
        for (int j = 1;j <= MC;++j) {
            for (;p[j] < m && j >= (b[p[j]] + b[i] - 1) / b[i];p[j]++) dp[p[j] + 1] = std::min(dp[p[j] + 1], dp[i] + j);
        }
    }
    std::cout << dp.back();
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