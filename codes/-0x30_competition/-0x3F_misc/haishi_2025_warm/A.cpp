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
    std::cout << "? A B" << std::endl;
    int s;std::cin >> s;
    std::cout << "? C B" << std::endl;
    int t;std::cin >> t;
    if (s && t)std::cout << "! B" << std::endl;
    else if (s)std::cout << "! A" << std::endl;
    else if (t)std::cout << "! C" << std::endl;
}

signed main() {
    int t;std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}