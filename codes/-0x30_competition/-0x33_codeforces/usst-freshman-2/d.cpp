#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pt = std::pair<int, int>;

void solve() {
    std::string s;std::cin >> s;
    int n = s.length();
    std::vector<int> suf1(n);
    for (int i = n - 2;i >= 0;i--)
        suf1[i] = suf1[i + 1] + (s[i + 1] == '1');

    int sum1 = 0, sum0 = 0;
    int ans = n;
    for (int i = 0, j = 0;j < n;++i) {
        while (j < n && sum1 + suf1[j] > sum0) {
            sum0 += s[j] == '0';
            j++;
        }
        if (j == n)break;
        ans = std::min(ans, std::max(sum0, sum1 + suf1[j]));
        sum1 += s[i] == '1';
        sum0 -= s[i] == '0';
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