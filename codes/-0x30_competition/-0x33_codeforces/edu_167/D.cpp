#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<i64, i64>;

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int n, m;std::cin >> n >> m;

    std::vector<pii> weapon(n);
    std::vector<i64> a(n), b(n), c(m);
    for (auto& x : a)std::cin >> x;
    for (auto& x : b)std::cin >> x;
    for (auto& x : c)std::cin >> x;
    for (int i = 0;i < n;++i)weapon[i].first = a[i], weapon[i].second = b[i];

    std::sort(weapon.begin(), weapon.end(), [&](pii a, pii b) {
        auto [x1, y1] = a;
        auto [x2, y2] = b;
        if (x1 - y1 != x2 - y2)return x1 - y1 < x2 - y2;
        return x1 < x2;
        });
    std::vector<pii> canuse;
    canuse.push_back(weapon[0]);
    for (int i = 1;i < n;++i) {
        if (weapon[i].first < canuse.back().first) {
            canuse.push_back(weapon[i]);
        }
    }
    std::reverse(canuse.begin(), canuse.end());
    std::vector<i64> dp(MAXN, 0);
    for (int i = 0, j = 0;i <= N;++i) {
        while (j < canuse.size() - 1 && canuse[j + 1].first <= i)j++;
        if (i >= canuse[j].first)
            dp[i] = dp[i - canuse[j].first + canuse[j].second] + 2;
    }

    i64 ans = 0;
    for (int i = 0;i < m;++i) {
        if (c[i] > N) {
            int cz = canuse.back().first - canuse.back().second;
            i64 cnt = (c[i] - canuse.back().first) / cz + 1;
            ans += 2 * cnt;
            c[i] -= cnt * cz;
        }
        ans += dp[c[i]];
    }
    std::cout << ans;
    return 0;
}