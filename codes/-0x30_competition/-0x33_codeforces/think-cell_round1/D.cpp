#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10;
int n;
using pt = std::pair<int, int>;

void solve() {
    std::cin >> n;
    std::string s;
    std::cin >> s;
    std::vector<std::array<i64, 3>> vt3(n + 1);
    i64 ans = 0, res = 0;
    for (int i = 1;i <= n;++i) {
        int cur = s[i - 1] - '0';
        if (cur) {
            vt3[i][0] = vt3[i - 1][1];
            vt3[i][1] = vt3[i - 1][2];
            vt3[i][2] = vt3[i - 1][0] + 1;
            ans += vt3[i][2];
        }
        else {
            vt3[i][0] = vt3[i - 1][0] + vt3[i - 1][1] + 1;
            vt3[i][1] = vt3[i - 1][2];
        }
        res += ans;
    }
    std::cout << res;
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