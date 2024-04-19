#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pt = std::pair<i64, i64>;

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::string s;
    std::cin >> s;
    std::vector<std::vector<i64>> pre0(n + 1, std::vector<i64>(n + 1));
    std::vector<std::vector<i64>> suf0(n + 1, std::vector<i64>(n + 1));
    for (int l = 0; l < n; ++l) {
        int cnt1 = 0;
        for (i64 r = l + 1; r <= n; ++r) {
            cnt1 += s[r - 1] == '1';
            pre0[r][cnt1] = std::max(pre0[r][cnt1], r - l);
            suf0[l][cnt1] = std::max(suf0[l][cnt1], r - l);
        }
    }

    for (int i = 0;i < n;++i)for (int j = 0;j <= n;++j) {
        if (i)
            pre0[i][j] = std::max(pre0[i][j], pre0[i - 1][j]);
        if (j)
            pre0[i][j] = std::max(pre0[i][j], pre0[i][j - 1]);
    }
    for (int i = n - 1;i >= 0;--i)for (int j = 0;j <= n;++j) {
        if (i <= n - 1)
            suf0[i][j] = std::max(suf0[i][j], suf0[i + 1][j]);
        if (j)
            suf0[i][j] = std::max(suf0[i][j], suf0[i][j - 1]);
    }

    std::vector<i64> ans(n + 1, -inf), f(n + 1, -inf);
    for (int l = 0;l < n;++l) {
        int cnt0 = 0;
        for (int r = l;r <= n;++r) {
            if (r > l)cnt0 += s[r - 1] == '0';
            if (cnt0 > k)break;
            f[r - l] = std::max(f[r - l], pre0[l][k - cnt0]);
            f[r - l] = std::max(f[r - l], suf0[r][k - cnt0]);
        }
    }
    for (int a = 1;a <= n;++a) {
        for (int len = 0;len <= n;++len) {
            ans[a] = std::max(ans[a], len + f[len] * a);
        }
        std::cout << ans[a] << ' ';
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