#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;

void solve() {
    int n;std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0;i < n;++i)std::cin >> a[i];
    std::vector<int> ans;
    for (int i = 0;i < 30;++i) {
        std::ranges::sort(a);
        if ((a.back() - a.front()) % 2 == 1) {
            std::cout << -1;
            return;
        }
        if (a.back() == 0 && a.front() == 0)break;
        ans.push_back((a.back() - a.front()) / 2 + a.front());
        for (int i = 0;i < n;++i)a[i] -= ans.back(), a[i] = std::abs(a[i]);
    }
    std::cout << ans.size() << '\n';
    for (int x : ans)std::cout << x << ' ';
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