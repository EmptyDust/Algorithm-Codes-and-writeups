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
    int n, k;std::cin >> n >> k;
    if (n != 1 && k != 1) {
        std::cout << "NO";
        return;
    }
    if (n == 1) {
        for (int i = 1;i < k;++i) {
            n = n * 10 + 1;
        }
    }
    if (n == 1 && k == 1) {
        std::cout << "NO";
        return;
    }
    int sq = std::sqrt(n);
    for (int i = 2;i <= sq;++i) {
        if (n % i == 0) {
            std::cout << "NO";
            return;
        }
    }
    std::cout << "YES";
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