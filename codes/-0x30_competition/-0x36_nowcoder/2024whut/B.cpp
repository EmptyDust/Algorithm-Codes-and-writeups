#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    std::string s;std::cin >> s;
    if (s[0] == '0') {
        std::cout << s;
        return 0;
    }
    for (char& ch : s) {
        if (ch == '1')ch = '0';
        else ch = '1';
    }
    s[0] = '1';
    for (int i = 31;i >= 0;--i) {
        if (s[i] == '1')s[i] = '0';
        else {
            s[i] = '1';
            break;
        }
    }
    std::cout << s;
    return 0;
}