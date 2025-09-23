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
    // 5 3 1 1 3 5 2 * * 2
    // 6 4 2 5 2 4 6 3 5 1 1 3
    // 
    // 6 5 4 3 2 1 6 1 2 3 4 5
    // 5 4 3 2 1 5 1 2 3 4
    int n;std::cin >> n;
    std::cout << n << ' ';
    for (int i = n - 1;i >= 1;i--) std::cout << i << ' ';
    std::cout << n << ' ';
    for (int i = 1;i <= n - 1;++i) std::cout << i << ' ';
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