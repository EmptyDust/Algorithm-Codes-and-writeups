#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
int nums[MAXN], n;
using pt = std::pair<int, int>;

void solve() {
    int n, m;std::cin >> n >> m;
    std::map<char, int> mp;
    std::string s;
    std::cin >> s;
    for (auto ch : s)mp[ch]++;
    i64 ans = 0;
    for (auto ch = 'A';ch <= 'G';++ch) {
        if (mp[ch] < m)ans += m - mp[ch];
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