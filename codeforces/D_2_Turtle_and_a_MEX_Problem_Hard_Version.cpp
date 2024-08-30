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
    i64 n, m;std::cin >> n >> m;
    std::vector<pii> p(n);
    i64 mxsize = 0;
    for (int i = 0;i < n;++i) {
        i64 k;std::cin >> k;
        mxsize = std::max(mxsize, k);
        std::vector<int> a(k);
        for (int& x : a)std::cin >> x;
        ranges::sort(a);
        int mex = 0;
        bool ok = true;
        for (int j = 0;j < k;++j) {
            if (a[j] > mex) {
                if (ok) {
                    p[i].first = mex;
                    mex++;
                    ok = false;
                }
                else break;
            }
            if (a[j] == mex)mex++;
        }
        // auto [l, r] = p[i];
        // std::cout << l << ' ' << r << " " << mex << "\n";
        if (ok) {
            p[i].first = mex;
            mex++;
            ok = false;
        }
        p[i].second = mex;
    }
    mxsize += 10;
    std::vector<i64> dp(mxsize, 0), cnt(mxsize, 0);
    std::iota(dp.begin(), dp.end(), 0);
    for (auto& [l, r] : p)cnt[l]++;
    ranges::sort(p, std::greater<pii>());
    i64 res = 0;
    for (auto& [l, r] : p) {
        // std::cout << l << ' ' << r << "\n";
        dp[l] = std::max(dp[l], dp[r]);
        res = std::max(res, 1ll * l);
    }
    for (int i = 0;i < mxsize;++i) {
        if (cnt[i] > 1) {
            res = std::max(res, dp[i]);
        }
    }
    // for (auto& x : dp)std::cout << x << ' ';
    // std::cout << res << " ";
    i64 ans = 0;
    if (m >= mxsize) {
        ans += (mxsize + m) * (m - mxsize + 1) / 2;
    }
    for (int i = 0;i < std::min(mxsize, m + 1); ++i) {
        ans += std::max(res, dp[i]);
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