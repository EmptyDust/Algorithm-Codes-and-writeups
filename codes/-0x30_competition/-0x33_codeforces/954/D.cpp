#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;

void solve() {
    int n;std::cin >> n;
    std::string s;std::cin >> s;
    if (n == 2) {
        std::cout << std::stoi(s);
        return;
    }
    if (n != 3) {
        if (std::count(s.begin(), s.end(), '0')) {
            std::cout << 0;
            return;
        }
    }
    else if (s[0] == '0' || s[2] == '0') {
        std::cout << 0;
        return;
    }
    int ans = inf;
    if (n == 3) {
        ans = std::min(ans, std::stoi(s.substr(1, 2)) * std::stoi(s.substr(0, 1)));
        ans = std::min(ans, std::stoi(s.substr(1, 2)) + std::stoi(s.substr(0, 1)));
        ans = std::min(ans, std::stoi(s.substr(0, 2)) * std::stoi(s.substr(2, 1)));
        ans = std::min(ans, std::stoi(s.substr(0, 2)) + std::stoi(s.substr(2, 1)));
        std::cout << ans;
        return;
    }
    for (int i = 0;i < n - 1;++i) {
        int res = std::stoi(s.substr(i, 2));
        for (int j = i + 2;j < n;++j) {
            if (s[j] == '1')continue;
            res += s[j] - '0';
        }
        for (int j = 0;j < i;++j) {
            if (s[j] == '1')continue;
            res += s[j] - '0';
        }
        ans = std::min(ans, res);
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