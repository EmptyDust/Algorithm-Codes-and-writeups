#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9 + 100, mod = 1e9 + 7;
using pii = std::pair<int, int>;

void solve() {
    int n, m;std::cin >> n >> m;
    std::vector<std::vector<int>> a(n, std::vector<int>(m)), ans(a);
    for (auto& vt : a)for (int& x : vt)std::cin >> x;
    auto vaild = [&](int x, int y) {
        return 0 <= x && x < n && 0 <= y && y < m;
        };
    pii dir[4] = { {1,0},{-1,0},{0,1},{0,-1} };
    auto cal = [&](int x, int y) {
        int max = -1;
        for (int i = 0;i < 4;++i) {
            int nx = x + dir[i].first, ny = y + dir[i].second;
            if (vaild(nx, ny)) {
                if (a[nx][ny] >= a[x][y])return -1;
                else max = std::max(max, a[nx][ny]);
            }
        }
        return max;
        };
    for (int i = 0;i < n;++i)for (int j = 0;j < m;++j) {
        int res = cal(i, j);
        if (res == -1)ans[i][j] = a[i][j];
        else ans[i][j] = res;
    }
    for (auto& vt : ans) {
        for (int& x : vt)std::cout << x << ' ';
        std::cout << '\n';
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