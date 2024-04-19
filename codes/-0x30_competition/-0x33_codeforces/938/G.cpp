#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e2 + 10;
int map[MAXN][MAXN], n, m;
bool f[MAXN][MAXN];
using pt = std::pair<int, int>;

bool check(int x) {
    f[0][0] = 1;
    for (int i = 0;i < n;++i)for (int j = 0;j < m;++j) {
        if (!i && !j)continue;
        if (map[i][j] % x == 0) {
            if (i && f[i - 1][j] || j && f[i][j - 1])f[i][j] = 1;
            else f[i][j] = 0;
        }
        else f[i][j] = 0;
    }
    return f[n - 1][m - 1];
}

void solve() {
    std::cin >> n >> m;
    for (int i = 0;i < n;++i)for (int j = 0;j < m;++j)std::cin >> map[i][j];
    int x = std::__gcd(map[0][0], map[n - 1][m - 1]);
    std::vector<int> y;
    for (int i = 1;i <= std::sqrt(x);++i)if (x % i == 0) {
        y.push_back(i);
        if (check(x / i)) {
            std::cout << x / i;
            return;
        }
    }
    std::reverse(y.begin(), y.end());
    for (int num : y)if (check(num)) {
        std::cout << num;
        return;
    }
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