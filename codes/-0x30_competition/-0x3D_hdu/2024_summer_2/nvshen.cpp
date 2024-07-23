#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;

void solve() {
    std::string s;std::cin >> s;
    char a = s[0], b = s[4];
    if (a == b) {
        std::cout << a;
        return;
    }
    int ca = std::count(s.begin(), s.end(), a);
    int cb = std::count(s.begin(), s.end(), b);
    if (ca > cb) {
        std::cout << a;
    }
    else if (ca < cb) {
        std::cout << b;
    }
    else {
        std::cout << "N";
    }
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