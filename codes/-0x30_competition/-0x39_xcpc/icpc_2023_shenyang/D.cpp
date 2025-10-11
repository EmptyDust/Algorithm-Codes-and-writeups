#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using u128 = unsigned __int128;

using a2 = std::array<int, 2>;
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

i64 minus;

i64 sol1(std::string s, std::string t) {
    int n = s.length();
    int m = t.length();
    std::vector cnt(n, std::vector<int>(n + 1));
    for (int i = 0;i < n;++i) {
        auto tmp = s.substr(i, n - i) + t;
        auto zf = z_function(tmp);
        for (int j = n - i;j < n - i + m;++j) {
            if (zf[j]) cnt[i][i + std::min(zf[j], n - i) - 1]++;
        }
    }
    for (int i = 0;i < n;++i) {
        for (int j = n - 1;j > i;--j) {
            cnt[i][j - 1] += cnt[i][j];
        }
    }
    minus = 0;
    for (int i = 0;i < n;++i) {
        for (int j = 0;j < n;++j) {
            minus += cnt[i][j];
        }
    }
    for (int r = 0;r < n;++r) {
        for (int l = 0;l < r;++l) {
            cnt[l + 1][r] += cnt[l][r];
        }
    }
    i64 ans = 0;
    for (int l = 0;l < n;++l) {
        auto tmp = s.substr(l, n - l);
        auto zf = z_function(tmp);zf.push_back(0);
        for (int j = 1;j <= n - l;++j) {
            int len = std::min(zf[j], j - 1);
            int r = l + len;
            int s = l + j;
            ans += cnt[r][s - 1] - (l ? cnt[l - 1][s - 1] : 0);
        }
    }
    return ans;
}

void solve() {
    std::string s, t;std::cin >> s >> t;
    i64 ans = sol1(s, t);
    ans -= minus;
    ranges::reverse(s);
    ranges::reverse(t);
    ans += sol1(t, s);
    std::cout << ans;
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