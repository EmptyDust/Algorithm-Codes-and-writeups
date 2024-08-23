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
    int n, x;std::cin >> n >> x;
    const int B = 2000;
    std::vector<int> canuse, dp(B + 10, inf), pre(B + 10);dp[0] = 0;
    for (int i = 1;i < B;++i) {
        if (std::__gcd(x, i) == 1) {
            canuse.push_back(i);
        }
    }
    for (int i = 0;i < B;++i) {
        for (int x : canuse) {
            if (i + x > B)break;
            if (dp[i + x] > dp[i] + 1) {
                dp[i + x] = dp[i] + 1;
                pre[i + x] = i;
            }
        }
    }
    int res = inf, resp = inf;
    bool f;
    std::vector<int> ans;
    for (int i = std::max(1, n - B);i <= n + B;++i) {
        if (std::__gcd(i, x) == 1) {
            if (res > 1 + dp[std::abs(i - n)]) {
                res = 1 + dp[std::abs(i - n)];
                ans = { i };
                resp = std::abs(i - n);
                f = i < n;
            }
        }
    }
    std::cout << res << '\n';
    while (resp) {
        int p = pre[resp];
        ans.push_back((resp - p) * (f ? 1 : -1));
        resp = p;
    }
    for (int x : ans)std::cout << x << ' ';
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t = 1;
    while (t--) {
        solve();
        std::cout << '\n';
    }
    return 0;
}