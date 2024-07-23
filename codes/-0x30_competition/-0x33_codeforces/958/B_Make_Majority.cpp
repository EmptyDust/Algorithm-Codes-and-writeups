#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;

void solve() {
    int n;std::cin >> n;
    std::string s;std::cin >> s;
    int cnt1 = 0, cnt0 = 0;
    for (int i = 0;i < n;++i) {
        if (s[i] == '0') {
            if (i == 0 || s[i - 1] == '1')cnt0++;
        }
        else cnt1++;
    }
    std::cout << (cnt1 > cnt0 ? "Yes" : "No");
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