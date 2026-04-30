#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;

void solve() {
    std::string s;std::cin >> s;
    int n = s.length();
    std::map<i64, i64> mp;
    mp[0]++;
    int cur = 0;
    i64 ans = 0;
    for (int i = 0;i < n;++i) {
        char ch = s[i];
        if (ch == '1')cur++;
        else cur--;
        ans = (ans + mp[cur] * (n - i) % mod) % mod;
        // std::cout << ans << ' ';
        mp[cur] = (mp[cur] + i + 2) % mod;
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