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
    std::string s;std::cin >> s;
    int n = s.length();
    int ac = 0;
    std::vector cnt(4, std::vector<int>(4));
    for (int i = 0;i < n; ++i) {
        switch (s[i])
        {
        case 'b':
            cnt[i % 4][0]++;
            break;
        case 'l':
            cnt[(i + 3) % 4][1]++;
            break;
        case 'u':
            cnt[(i + 2) % 4][2]++;
            break;
        case 'e':
            cnt[(i + 1) % 4][3]++;
        default:
            break;
        }
    }
    std::array<int, 4> a = { inf,inf,inf,inf };
    for (int i = 0;i < 4;++i) {
        for (int j = 0;j < 4;++j) {
            a[i] = std::min(a[i], cnt[i][j]);
            // std::cout << cnt[i][j] << ' ';
        }
        // std::cout << '\n';
    }
    i64 ans = 0;
    for (int i = 0;i < 4;++i)
        if (a[i]) {
            ans += a[i];
            ac++;
        }
    if (ac > 1 && n == ans * 4) {
        ans--;
    }
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