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
    int n;std::cin >> n;
    std::vector<pii> p(n);
    for (auto& [x, y] : p)std::cin >> x >> y;
    ranges::sort(p, [&](pii a, pii b){
        if (std::min(a.first, a.second) == std::min(b.first, b.second))
            return std::max(a.first, a.second) < std::max(b.first, b.second);
        return std::min(a.first, a.second) < std::min(b.first, b.second);
        });
    for (auto [x, y] : p)std::cout << x << ' ' << y << ' ';
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