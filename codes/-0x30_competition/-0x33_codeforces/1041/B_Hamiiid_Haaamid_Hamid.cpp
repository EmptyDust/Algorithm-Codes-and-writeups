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
    int n, m;std::cin >> n >> m;
    std::string s;std::cin >> s;
    s = '*' + s;
    int cnt0 = m - 1, cnt1 = n - m;
    for (int i = m + 1;i <= n;++i) {
        if (s[i] == '.')cnt1--;
        else break;
    }
    for (int i = m - 1;i >= 1;--i) {
        if (s[i] == '.')cnt0--;
        else break;
    }
    int ans = std::max(cnt0, cnt1);
    // std::cout << cnt0 << ' ' << cnt1 << '\n';
    ans = std::min({ ans, m - 1,n - m });
    std::cout << ans + 1;
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