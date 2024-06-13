#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pt = std::pair<int, int>;

void solve() {
    std::string s;std::cin >> s;
    if (s[0] != '1') {
        std::cout << "NO";
        return;
    }
    std::reverse(s.begin(), s.end());
    int n = s.length();
    for (int i = 0;i < n;++i) {
        int x = s[i] - '0';
        if (!i) {
            if (x == 9) {
                std::cout << "NO";
                return;
            }
        }
        else {
            x--;
            if (x == -1) {
                std::cout << "NO";
                return;
            }
        }
    }
    std::cout << "YES";
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