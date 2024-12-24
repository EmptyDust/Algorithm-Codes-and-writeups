#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using d64 = long double;

using pii = std::pair<int, int>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
// const int mod = 1e9 + 7;
const int mod = 998244353;

const d64 eps = 1e-8;

void solve() {
    int n, l, r;
    d64 p;
    std::cin >> n >> p >> l >> r;
    d64 Ex = 1 / (p * p);
    d64 Dx = (p * p + (1 - p) * (2 + p)) / p - Ex;
    d64 ans = 0;
    for (int i = 0;i < n;++i) {
        
    }
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