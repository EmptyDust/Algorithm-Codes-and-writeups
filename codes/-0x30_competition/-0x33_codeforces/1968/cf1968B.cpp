#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
int nums[MAXN], m, n;
using pt = std::pair<int, int>;

void solve() {
    std::cin >> n >> m;
    std::string s, t;std::cin >> s >> t;
    int ans = 0;
    for (int i = 0, j = 0;j < m && i < n;++j) {
        if (s[i] == t[j])++i;
        ans = std::max(ans, i);
    }
    std::cout << ans;
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