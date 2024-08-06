#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;

void solve() {
    int n;std::cin >> n;
    std::string s;std::cin >> s;
    std::set<int, std::greater<int>> ls;
    std::set<int> rs;
    ls.insert(0);
    for (int i = 2;i < n;i += 2)rs.insert(i);
    i64 ans = 0;
    for (int i = 1;i < n;i += 2) {
        if (s[i] == '(') {
            // std::cout << i << ' ' << *rs.begin() << '\n';
            ans += *rs.begin() - i;
            rs.erase(rs.begin());
        }
        else {
            // std::cout << *ls.begin() << ' ' << i << '\n';
            ans += i - *ls.begin();
            ls.erase(ls.begin());
        }
        if (rs.count(i + 1)) {
            rs.erase(i + 1);
            ls.insert(i + 1);
        }
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