#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
int nums[MAXN], n;
using pt = std::pair<int, int>;

void solve() {
    std::string s;std::cin >> s;
    for (int i = 1;i < s.length();++i) {
        if (s[i] != s[i - 1]) {
            std::swap(s[i], s[i - 1]);
            std::cout << "Yes\n";
            std::cout << s;
            return;
        }
    }
    std::cout << "No";
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