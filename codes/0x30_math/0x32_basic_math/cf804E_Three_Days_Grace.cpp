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
    std::vector<i64> appear(m + 1), mex(m + 1), dp(m + 1);
    int min = inf, max = 0;
    for (int i = 0;i < n;++i) {
        int x;std::cin >> x;
        appear[x]++;
        mex[x]++;
        min = std::min(min, x);
        max = std::max(max, x);
    }
    for (int i = 0;i <= max;++i)dp[i] = i;
    int ans = max - min;
    int p = max;
    for (int L = max;L >= 1;--L) {
        for (i64 i = 1ll * L * L;i <= max;i += L) {
            if (appear[i])mex[dp[i]] -= appear[i];
            dp[i] = std::min(dp[i], dp[i / L]);
            if (appear[i])mex[dp[i]] += appear[i];
        }
        while (!mex[p])p--;
        if (L <= min)ans = std::min(ans, p - L);
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