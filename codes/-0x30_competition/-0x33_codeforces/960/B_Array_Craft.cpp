#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;

void solve() {
    int n, x, y;std::cin >> n >> x >> y;x--, y--;
    std::vector<int> ans;
    for (int i = 0;i < y;++i) {
        ans.push_back(y % 2 == i % 2 ? 1 : -1);
    }
    for (int i = y;i <= x;++i) {
        ans.push_back(1);
    }
    for (int i = x + 1;i < n;++i) {
        ans.push_back(x % 2 == i % 2 ? 1 : -1);
    }
    for (int x : ans)std::cout << x << ' ';
}
// 4 2 3

// -1 1 1 -1 
//4 1 4
// 1 1 1 1

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