#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;

void solve() {
    int n;std::cin >> n;
    i64 k;std::cin >> k;
    if (k & 1) {
        std::cout << "No";
        return;
    }
    std::vector<int> ans(n + 1);
    std::iota(ans.begin(), ans.end(), 0);
    for (int i = 1, j = n;i < j;) {
        if (std::abs(j - i) * 2 <= k) {
            k -= std::abs(j - i) * 2;
            std::swap(ans[i], ans[j]);
            i++, j--;
        }
        else j--;
    }
    if (k) {
        std::cout << "No";
        return;
    }
    std::cout << "Yes\n";
    for (int i = 1;i <= n;++i)std::cout << ans[i] << ' ';
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