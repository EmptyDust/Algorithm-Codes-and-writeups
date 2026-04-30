#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
int nums[MAXN], n;
using pt = std::pair<int, int>;

void solve() {
    std::string s;
    std::cin >> s;
    int ans = 1;
    int n = s.length();
    bool f = true;
    for (int i = 1;i < n;++i) if (s[i] != s[i - 1]) {
        if (s[i] == '1') {
            if (f)f = false;
            else ans++;
        }
        else {
            ans++;
        }
    }
    std::cout << ans;
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