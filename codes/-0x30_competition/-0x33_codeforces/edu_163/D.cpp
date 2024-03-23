#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10;
int nums[MAXN], n;
using pt = std::pair<int, int>;

void solve() {
    std::string s;
    std::cin >> s;
    int n = s.length();
    int ans = 0;
    for (int len = 1;len < n;++len) {
        int cur = 0;
        for (int i = 0;i < n - len;++i) {
            if (s[i] == s[i + len] || s[i] == '?' || s[i + len] == '?') {
                cur++;
            }
            else
                cur = 0;
            if (cur == len) {
                ans = cur * 2;
                break;
            }
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