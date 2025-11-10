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

char ch[7] = { 'O', 'B', 'A', 'F', 'G', 'K','M' };

void solve() {
    a2 a, b;
    char x;
    std::cin >> x >> a[1];
    for (int i = 0;i < 7;++i) if (x == ch[i])a[0] = i;
    std::cin >> x >> b[1];
    for (int i = 0;i < 7;++i) if (x == ch[i])b[0] = i;
    if (a < b) {
        std::cout << "hotter";
    }
    else if (a == b) {
        std::cout << "same";
    }
    else {
        std::cout << "cooler";
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