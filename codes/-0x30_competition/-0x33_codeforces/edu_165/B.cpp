#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
int nums[MAXN], n;
using pt = std::pair<int, int>;

void solve() {
    std::string s;std::cin >> s;
    int n = s.length();
    i64 ans = 0;
    int l = 0, r = 0;
    while (l < n && s[l] == '0')l++, r++;
    for (;r < n;++r) {
        if (s[r] == '0') {
            ans += r - l + 1;
            l++;
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