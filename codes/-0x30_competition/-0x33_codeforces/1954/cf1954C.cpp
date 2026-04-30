#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10;
using pt = std::pair<int, int>;

void solve() {
    std::string s, t;
    std::cin >> s >> t;
    int i = 0;
    int n = s.length();
    while (i < n && s[i] == t[i])i++;
    if (i == n) {
        std::cout << s << '\n' << t;
        return;
    }
    if (s[i] < t[i])std::swap(s[i], t[i]);i++;
    while (i < n) {
        if (s[i] > t[i])
            std::swap(s[i], t[i]);
        ++i;
    }
    std::cout << s << '\n' << t;
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