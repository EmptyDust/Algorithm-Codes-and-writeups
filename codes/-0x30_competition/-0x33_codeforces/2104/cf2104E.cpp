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
    int n, k;std::cin >> n >> k;
    std::string s;std::cin >> s;
    s = '&' + s;
    std::vector next(n + 1, std::vector<int>(k, -1));
    for (int x = 0;x < k;++x) {
        int nxt = -1;
        for (int i = n;i >= 0;--i) {
            next[i][x] = nxt;
            if (s[i] - 'a' == x) {
                nxt = i;
            }
        }
    }
    std::vector<int> ans(n + 1, inf);
    for (int i = n;i >= 0;--i) {
        for (int x = 0;x < k;++x) {
            if (next[i][x] == -1)ans[i] = 1;
            else ans[i] = std::min(ans[i], ans[next[i][x]] + 1);
        }
    }
    int q;std::cin >> q;
    while (q--) {
        std::string t;std::cin >> t;
        int x = 0;
        for (int i = 0;i < t.length();++i) {
            x = next[x][t[i] - 'a'];
            if (x == -1) {
                std::cout << 0 << '\n';
                break;
            }
        }
        if (x >= 0) std::cout << ans[x] << '\n';
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t = 1;//std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}