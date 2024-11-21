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
    int a, b, c;std::cin >> a >> b >> c;
    std::cout << "100\n";
    for (int i = 0;i < 50;++i)std::cout << a << " ";
    for (int i = 50;i < 95;++i)std::cout << b << " ";
    for (int i = 95;i < 99;++i)std::cout << c << " ";
    for (int i = 99;i < 100;++i)std::cout << c + 1 << " ";
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