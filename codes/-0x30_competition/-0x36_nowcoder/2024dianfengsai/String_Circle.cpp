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

std::vector<int> get_pos(std::string s, std::string t){
    int n = s.length();
    s = t + s + s;
    auto zf = z_function(s);
    std::vector<int> ans(n + 1);
    for (int i = n;i <= 2 * n;++i){
        if (zf[i] >= n){
            ans[i - n] = 1;
        }
    }
    return ans;
}
//0 -> 0,1,2,3,4,..,n
//tj 不能开始
void solve() {
    int n, k;std::cin >> n >> k;
    std::vector<std::string> str(k);
    for (auto& s : str)std::cin >> s;
    std::vector<i64> dp(n + 1);dp[0] = 1;
    for (int i = 1;i < k;++i){
        auto pos = get_pos(str[0], str[i]);
        std::vector<i64> ndp(n + 1);
        for (int j = 0;j <= n;++j){
            dp[j] = (dp[j] + (j ? dp[j - 1] : 0)) % mod;
            if (pos[j]){
                // std::cout << i << ' ' << j << ' ' << dp[j] << '\n';
                ndp[j] = dp[j];
            }
        }
        dp = ndp;
    }
    i64 ans = 0;
    for (auto x : dp)ans = (ans + x) % mod;
    std::cout << ans << '\n';
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