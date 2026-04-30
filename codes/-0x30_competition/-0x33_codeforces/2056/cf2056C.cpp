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
    //123123
    //1234123
    //11234512
    int n;std::cin >> n;
    if (n % 2) {
        for (int i = 0;i < n / 2 + 1;++i)std::cout << i + 1 << ' ';
        for (int i = 0;i < n / 2;++i)std::cout << i + 1 << ' ';
    }
    else {
        std::cout << 1 << ' ';
        for (int i = 0;i < n - 3;++i)std::cout << i + 1 << ' ';
        std::cout << 1 << ' ' << 2 << ' ';
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