#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;

void solve() {
    std::string s;std::cin >> s;
    int cur = -1;
    for (int i = 0;i < s.length() - 1;++i) {
        if (s[i] == s[i + 1]) {
            cur = i;
            break;
        }
    }
    // std::cout << cur << ' ';
    if (cur == -1) {
        if (s[0] == 'a')s = 'b' + s;
        else s = 'a' + s;
    }
    else {
        char x = s[cur] == 'a' ? 'b' : 'a';
        s = s.substr(0, cur + 1) + x + s.substr(cur + 1, s.length() - cur - 1);
    }
    std::cout << s;
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