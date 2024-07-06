#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;

void solve() {
    std::string s, t;
    std::cin >> s >> t;
    std::string pre, suf;
    std::vector<int> cur(t.length());
    for (int i = 0;i < t.length();++i)cur[i] = i;
    for (int i = 0;i < s.length();++i) {
        for (int& x : cur) {
            if (x < t.length() && t[x] == s[i])x++;
        }
    }
    int ans = -1;
    for (int i = 0;i < t.length();++i) {
        ans = std::max(ans, cur[i] - i);
    }
    int res = (int)s.length() + (int)t.length() - ans;
    std::cout << res;
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