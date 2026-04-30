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
    int n;std::cin >> n;
    std::vector<a3> edges(n);
    for (auto& [x, y, id] : edges) std::cin >> x >> y;
    for (int i = 0;i < n;++i) edges[i][2] = i;
    ranges::sort(edges);
    int last = 0;
    std::vector<int> ans;
    for (auto& [x, y, id] : edges) {
        if (y >= last) {
            ans.push_back(id);
            last = y + 1;
        }
    }
    std::cout << ans.size() << '\n';
    for (auto& x : ans) std::cout << x + 1 << ' ';
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