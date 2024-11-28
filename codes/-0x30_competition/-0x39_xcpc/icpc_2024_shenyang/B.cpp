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
    int n, m;std::cin >> n >> m;
    if (std::__gcd(n, m) != 1) {
        std::cout << "No\n";
        return;
    }
    std::cout << "Yes\n";
    if (n == 1 && m == 1) {
        std::cout << "0\n";
        std::cout << "0\n";
        return;
    }
    if (n == 1) {
        std::cout << "1\n";
        for (int i = 0;i < m;++i)std::cout << i << ' ';
        std::cout << '\n';
        return;
    }
    if (m == 1) {
        for (int i = 0;i < n;++i)std::cout << i << ' ';
        std::cout << '\n';
        std::cout << "1\n";
        return;
    }
    for (int i = 0, j = 1;i < n;++i, j += m) {
        std::cout << j << ' ';
    }
    std::cout << '\n';
    for (int i = 0, j = 1;i < m;++i, j += n) {
        std::cout << j << ' ';
    }
    std::cout << '\n';
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t;std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}