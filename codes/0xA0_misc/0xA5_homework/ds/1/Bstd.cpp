#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<int, int>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
// const int mod = 1e9 + 7;
const int mod = 998244353;

void solve() {
    int n, m;std::cin >> n >> m;
    std::vector<std::vector<int>> matrix(n, std::vector<int>(m));
    for (int i = 0;i < n;++i)for (int j = 0;j < m;++j)std::cin >> matrix[i][j];
    for (int i = 0;i < n;++i) {
        for (int j = 0;j < m;++j) {
            bool ok = true;
            for (int x = 0;x < n;++x) {
                if (x != i && matrix[x][j] <= matrix[i][j]) {
                    ok = false;
                    break;
                }
            }
            for (int y = 0;y < m;++y) {
                if (y != j && matrix[i][y] >= matrix[i][j]) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                std::cout << "YES\n";
                std::cout << i + 1 << ' ' << j + 1;
                return;
            }
        }
    }
    std::cout << "NO";
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
