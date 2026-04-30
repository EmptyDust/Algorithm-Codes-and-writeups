#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;

void solve() {
    int n;std::cin >> n;
    std::vector<int> a(n + 1), b(n + 1), y(n + 1);
    for (int i = 0;i < n;++i)std::cin >> a[i], b[a[i]]++;
    std::vector<int> ky(n + 1, -1);
    ky[0] = 0;
    int cnt = 0;
    for (int i = 1;i <= n;++i) {
        if (b[i]) {
            cnt++;
            int ncnt = 0;

            std::vector<int> nky(n + 1, -1);
            for (int j = n;j >= b[i];j--) {
                int nj = j - b[i];
                if (ky[j] != -1)
                    nky[nj] = ky[j] + 1;
            }
            for (int j = n;j >= 0;--j) {
                int nj = std::min(n, j + 1);
                ky[nj] = std::max(ky[j], ky[nj]);
                ky[nj] = std::max(nky[nj], ky[nj]);
            }
            ky[0] = std::max(nky[0], ky[0]);

            // for (int j = 0;j <= n;++j)
            //     std::cout << ky[j] << ' ';
            // std::cout << '\n';
        }
    }
    int res = *std::max_element(ky.begin(), ky.end());
    std::cout << cnt - res;
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