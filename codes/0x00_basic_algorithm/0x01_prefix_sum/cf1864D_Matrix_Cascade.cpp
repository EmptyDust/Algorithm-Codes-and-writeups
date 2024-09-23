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
    int n;std::cin >> n;
    std::vector<std::vector<int>> g(n, std::vector<int>(n));
    for (int i = 0;i < n;++i)
        for (int j = 0;j < n;++j)
        {
            char ch;std::cin >> ch;
            g[i][j] = ch == '1';
        }
    std::vector<int> l(n + 1), r(n + 1);
    int ans = 0;
    for (int i = 0;i < n;++i) {
        std::vector<int> ch(n + 1);
        for (int j = 0;j < n;++j) {
            ch[j] = (j ? ch[j - 1] : 0) + l[j] - r[j];
        }
        for (int j = 0;j < n;++j) {
            if (ch[j] % 2 != g[i][j]) {
                l[j]++;
                r[j + 1]++;
                ans++;
            }
        }
        for (int j = 1;j < n;++j) {
            l[j - 1] += l[j];
            l[j] = 0;
        }
        for (int j = n - 1;j >= 0;--j) {
            r[j + 1] += r[j];
            r[j] = 0;
        }
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