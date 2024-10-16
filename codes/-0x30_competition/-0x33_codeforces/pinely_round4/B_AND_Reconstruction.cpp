#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;

void solve() {
    int n;std::cin >> n;
    std::vector<int> b(n - 1);
    for (int& x : b)std::cin >> x;
    std::vector<int> res(n);

    for (int i = 0;i < 30;++i) {
        std::vector<bool> a(n, 1);
        int suf = -1;
        for (int j = 0;j < n - 1;++j) {
            if (!(b[j] >> i & 1)) {
                if (suf == 0) {
                    suf = -1;
                    a[j] = 0;
                }
                else if (suf == 1) {
                    suf = 0;
                }
                else {
                    a[j] = 0;
                }
            }
            else {
                if (suf == 0) {
                    std::cout << -1;
                    return;
                }
                else if (suf == 1) {

                }
                else {
                    suf = 1;
                }
            }
            if (a[j])
                res[j] |= 1 << i;
            // if (i == 0)std::cout << j << ' ' << a[j] << ' ';
        }
        if (suf == 0)a[n - 1] = 0;
        if (a[n - 1])
            res[n - 1] |= 1 << i;
        // std::cout << '\n';
    }
    for (int x : res)std::cout << x << ' ';
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