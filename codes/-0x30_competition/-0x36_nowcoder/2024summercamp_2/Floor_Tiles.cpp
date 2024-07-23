#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;

void solve() {
    int n, m, k;std::cin >> n >> m >> k;
    int x, y;char ch;std::cin >> x >> y >> ch;
    bool t = ch != 'A';
    bool f = (x + y) % 2 == t;
    int cnt = n + m;
    if (cnt > k) {
        std::cout << "No\n";
        return;
    }
    int c = k - cnt;
    std::vector ans(n, std::vector<int>(m));
    for (int i = 0;i < n;++i)for (int j = 0;j < m;++j) {
        if (c > 0) {
            ans[i][j] = (i + j) % 2 == f;
            if (i && j && ans[i - 1][j] == 0 && ans[i][j - 1] == 0 && ans[i - 1][j - 1] == 1 && ans[i][j] == 1) {
                c--;
            }
        }
        else {
            // std::cout << i << ' ' << j << '\n';
            ans[i][j] = !f;
        }
    }
    if (c)std::cout << "No\n";
    else {
        std::cout << "Yes\n";
        for (int i = 0;i < n;++i) {
            for (int j = 0;j < m;++j) {
                std::cout << (ans[i][j] ? 'A' : 'B');
            }
            std::cout << '\n';
        }
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t;std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}