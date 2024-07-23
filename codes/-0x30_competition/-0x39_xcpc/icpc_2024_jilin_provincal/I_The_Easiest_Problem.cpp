#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    std::string s;
    int ans = 0;
    while (std::cin >> s) {
        for (char ch : s)if (std::islower(ch))ans++;
    }
    std::cout << ans;
    return 0;
}