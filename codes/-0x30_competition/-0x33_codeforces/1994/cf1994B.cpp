#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;

bool solve() {
    int n;std::cin >> n;
    std::string s, t;std::cin >> s;
    std::cin >> t;
    int f = -1;
    for (int i = 0;i < n;++i) {
        if (s[i] == '1') {
            f = i;
            break;
        }
    }
    if (f == -1 && s != t || s.substr(0, f) != t.substr(0, f)) {
        return false;
    }
    return true;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t;std::cin >> t;
    while (t--) {
        std::cout << (solve() ? "YES" : "NO");
        std::cout << '\n';
    }
    return 0;
}