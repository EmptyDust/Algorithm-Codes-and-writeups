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
    int n, q;std::cin >> n >> q;
    std::vector<int> b(n);
    for (auto& x : b)std::cin >> x;
    std::vector<a3> ops(q);
    for (auto& [x, y, z] : ops)std::cin >> x >> y >> z, x--, y--, z--;
    ranges::reverse(ops);
    std::vector<int> a(b);
    for (auto [x, y, z] : ops) {
        a[x] = std::max(a[x], a[z]);
        a[y] = std::max(a[y], a[z]);
        if (z != y && z != x) a[z] = 0;
    }
    std::vector<int> tmpa(a);
    ranges::reverse(ops);
    for (auto [x, y, z] : ops) {
        tmpa[z] = std::min(tmpa[x], tmpa[y]);
    }
    if (tmpa != b) {
        std::cout << -1;
    }
    else for (auto x : a)std::cout << x << " ";
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