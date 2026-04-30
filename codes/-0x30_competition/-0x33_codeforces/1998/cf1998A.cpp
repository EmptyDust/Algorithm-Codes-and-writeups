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
    int x, y, k;std::cin >> x >> y >> k;
    std::vector<pii> ans;
    if (k % 2)ans.push_back({ x,y });
    for (int i = 1;i <= k / 2;++i)ans.push_back({ x + i,y });
    for (int i = 1;i <= k / 2;++i)ans.push_back({ x - i,y });
    for (auto [x, y] : ans)std::cout << x << ' ' << y << '\n';
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