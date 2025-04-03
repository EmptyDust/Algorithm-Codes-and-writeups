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

std::vector<int> z_function(std::string s) {
    int n = (int)s.length();
    std::vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r && z[i - l] < r - i + 1) {
            z[i] = z[i - l];
        }
        else {
            z[i] = std::max(0, r - i + 1);
            while (i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];
        }
        if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
    }
    return z;
}

void solve() {
    std::string s;std::cin >> s;
    // std::cout << char('Z' + 1) << ' ';
    int n = s.length();
    std::vector dp(n, std::vector<int>(n, -1));
    std::vector trace(n, std::vector<pii>(n));
    for (int i = 0;i < n;++i) {
        dp[0][i] = 1;
    }
    for (int i = 0;i < n;++i) {
        for (int j = 1;j < n;++j) {
            if (dp[i][j] < dp[i][j - 1]) {
                dp[i][j] = dp[i][j - 1];
                trace[i][j] = { i,j - 1 };
            }
        }

        auto zf = z_function(s.substr(i));
        std::reverse(zf.begin(), zf.end());
        while (zf.size() < n)zf.push_back(0);
        std::reverse(zf.begin(), zf.end());

        // for (int x : zf)std::cout << x << " ";std::cout << '\n';
        for (int j = i + 1;j < n;++j) {
            int len = std::min(zf[j], j - i);
            if (j + len >= n)continue;
            if (dp[i][j - 1] == -1)continue;
            // if (len == 0 && j == 2)std::cout << "i:" << i << ' ';
            if (zf[j] >= j - i) {
                // std::cout << j + len << ' ' << n << '\n';
                if (dp[j][j + len] < dp[i][j - 1] + 1) {
                    dp[j][j + len] = dp[i][j - 1] + 1;
                    trace[j][j + len] = { i,j - 1 };
                }
            }
            else if (s[j + len] > s[i + len]) {
                if (dp[j][j + len] < dp[i][j - 1] + 1) {
                    dp[j][j + len] = dp[i][j - 1] + 1;
                    trace[j][j + len] = { i,j - 1 };
                }
            }
        }
        // for (int x : dp[i])std::cout << x << " ";std::cout << '\n';
    }
    std::vector<pii> ans;
    int cx = n - 1, cy = n - 1;
    int max = 0;
    for (int i = 0;i < n;++i) {
        if (dp[i][n - 1] > max) {
            cx = i;
            max = dp[i][n - 1];
        }
    }
    ans.push_back({ cx,cy });
    while (cx && cy) {
        auto [x, y] = trace[cx][cy];
        if (cx != x)ans.push_back({ x,y });
        cx = x, cy = y;
    }
    std::reverse(ans.begin(), ans.end());
    std::cout << max << '\n';
    for (auto [x, y] : ans)std::cout << s.substr(x, y - x + 1) << '\n';
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