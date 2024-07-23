#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;

std::vector<std::string> split(std::string s, std::string t) {
    std::vector<std::string> res;
    int p = 0;
    // std::cout << s.find(t, p);
    while (p < s.length() && s.find(t, p) != -1) {
        int np = s.find(t, p);
        res.push_back(s.substr(p, np - p));
        p = np + t.length();
    }
    if (p != s.length())
        res.push_back(s.substr(p, s.length() - p));
    return res;
}

void solve() {
    std::string s;std::cin >> s;
    auto a = split(s, "://");
    std::cout << a[0] << '\n';
    // std::cout << a[1];
    auto b = split(a[1], "/");
    std::cout << b[0] << '\n';
    for (int i = 1;i < b.size();++i) {
        if (std::count(b[i].begin(), b[i].end(), '=') == 1)
            std::cout << b[i] << '\n';
    }
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