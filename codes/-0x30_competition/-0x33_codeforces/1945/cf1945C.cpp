#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10;
int nums[MAXN], n;
using pt = std::pair<int, int>;

void solve() {
    int n;std::cin >> n;
    std::string s;std::cin >> s;
    int r = 0, l = 0;
    r = std::count(s.begin(), s.end(), '1');
    int ans = -1;
    for (int i = 0;i < n;++i) {
        if (r >= (n - i + 1) / 2 && l >= (i + 1) / 2) {
            if (std::abs(n / 2.0 - i) < std::abs(n / 2.0 - ans))ans = i;
        }
        l += s[i] == '0';
        r -= s[i] == '1';
    }
    if (l >= (n + 1) / 2) {
        if (std::abs(n / 2.0 - n) < std::abs(n / 2.0 - ans))ans = n;
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