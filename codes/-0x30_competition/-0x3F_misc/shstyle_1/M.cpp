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

std::string strs[5] = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday" };

void solve() {
    i64 y1, m1, d1, y2, m2, d2;std::string D;
    std::cin >> y1 >> m1 >> d1 >> D >> y2 >> m2 >> d2;
    int p = 0;
    for (;p < 5 && strs[p] != D;++p);
    i64 c = ((p + y2 * 12 * 30 + m2 * 30 + d2 - y1 * 12 * 30 - m1 * 30 - d1) % 5 + 5) % 5;
    std::cout << strs[c];
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