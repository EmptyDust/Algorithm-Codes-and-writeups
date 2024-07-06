#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;

void solve() {
    int n, m, k;std::cin >> n >> m >> k;
    std::vector<std::vector<i64>> map(n + 1, std::vector<i64>(m + 1));
    std::vector<std::vector<i64>> type(n + 1, std::vector<i64>(m + 1));
    std::vector<std::vector<i64>> pre2(n + 1, std::vector<i64>(m + 1));
    for (int i = 1;i <= n;++i)for (int j = 1;j <= m;++j)std::cin >> map[i][j];
    for (int i = 1;i <= n;++i) {
        std::string s;std::cin >> s;
        for (int j = 1;j <= m;++j) {
            type[i][j] = s[j - 1] == '1' ? 1 : -1;
        }
    }
    i64 sum = 0;
    for (int i = 1;i <= n;++i)for (int j = 1;j <= m;++j)sum += map[i][j] * type[i][j];
    for (int i = 1;i <= n;++i)for (int j = 1;j <= m;++j) {
        auto& cur = pre2[i][j] = type[i][j];
        cur += pre2[i][j - 1] + pre2[i - 1][j] - pre2[i - 1][j - 1];
    }

    if (sum == 0) {
        std::cout << "YES";
        return;
    }

    i64 gcd = -1;
    for (int i = k;i <= n;++i)for (int j = k;j <= m;++j) {
        i64 res = std::abs(pre2[i][j] - pre2[i - k][j] - pre2[i][j - k] + pre2[i - k][j - k]);
        // std::cout << i << ' ' << j << ' ' << res << '\n';
        if (res != 0) {
            if (gcd == -1) {
                gcd = res;
            }
            else gcd = std::__gcd(gcd, res);
        }
    }

    //std::cout << sum << ' ' << gcd << '\n';
    std::cout << (gcd == -1 || sum % gcd ? "NO" : "YES");
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