#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;

void solve() {
    int n;i64 lim;std::cin >> n >> lim;
    std::vector<int> a(n);
    for (int& x : a)std::cin >> x;
    std::vector<int> f(n, n);
    int ans = 0;

    for (int k = 29;k >= 0;--k) {
        std::map<int, int> p;
        auto nf = f;
        for (int i = 0;i < n;++i) {
            if (p.count((a[i] ^ ans) >> k)) {
                int j = p[(a[i] ^ ans) >> k];
                nf[j] = std::min(i, nf[j]);
            }
            p[a[i] >> k] = i;
        }
        for (int i = n - 2;i >= 0;--i) {
            nf[i] = std::min(nf[i], nf[i + 1]);
        }
        i64 sum = 0;
        for (int i = 0;i < n;++i) {
            sum += n - nf[i];
        }
        if (sum < lim) {
            ans |= 1 << k;
            f = nf;
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