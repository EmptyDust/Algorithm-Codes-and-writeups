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

void solve() {
    std::string s;
    std::cin >> s;
    int n = s.length();
    double ans = 0;
    for (int l = 0;l < n;++l) {
        for (int r = l + 2;r < n;++r) if (s[l] == 't' && s[r] == 't') {
            int cnt = 0;
            for (int i = l + 1;i <= r - 1;++i) {
                cnt += s[i] == 't';
            }
            // if (l == 1 && r == 4)std::cout << cnt << ' ';
            ans = std::max(ans, 1.0 * cnt / (r - l - 1));
        }
    }
    std::cout << ans;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    std::cout << std::fixed << std::setprecision(13);
    int t = 1;
    while (t--) {
        solve();
        std::cout << '\n';
    }
    return 0;
}