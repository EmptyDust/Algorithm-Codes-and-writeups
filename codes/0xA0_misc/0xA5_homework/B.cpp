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
    std::vector matrix(n, std::vector<int>(m));
    for (int i = 0;i < n;++i)for (int j = 0;j < m;++j)std::cin >> matrix[i][j];
    std::vector<int> a(n), b(m, inf);
    std::vector<int> pa(n), pb(m, inf);
    for (int i = 0;i < n;++i) {
        for (int j = 0;j < m;++j) {
            if (a[i] == matrix[i][j]) {
                pa[i] = -1;
            }
            if (a[i] < matrix[i][j]) {
                a[i] = matrix[i][j];
                pa[i] = j;
            }
        }
    }
    for (int j = 0;j < m;++j) {
        for (int i = 0;i < n;++i) {
            if (b[j] == matrix[i][j]) {
                pb[j] = -1;
            }
            if (b[j] > matrix[i][j]) {
                b[j] = matrix[i][j];
                pb[j] = i;
            }
        }
    }
    // std::cout << pa[0] << " ";
    for (int i = 0;i < n;++i) {
        if (pa[i] != -1 && pb[pa[i]] == i) {
            std::cout << "YES" << '\n';
            std::cout << i + 1 << ' ' << pa[i] + 1;
            return;
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
