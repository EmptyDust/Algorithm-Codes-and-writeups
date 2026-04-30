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
    int n, m, k;std::cin >> n >> m >> k;
    std::vector<i64> pcnt(k + 1), scnt(k + 1), p(m), s(m);
    std::vector<i64> pf(k + 1), sf(k + 1);
    i64 x = 0;
    for (int i = 0;i < n;++i) {
        for (int j = 0;j < m;++j) {
            int y;
            std::cin >> s[j];
            if (s[j] == -1)s[j] = 0;
            scnt[s[j]]++;
        }
        for (int y : p)sf[y] = std::max(x, pf[y]) + (pcnt[y] + pcnt[0]) * (scnt[y] + scnt[0]) - pcnt[y] * scnt[y];
        for (int y : s)sf[y] = std::max(x, pf[y]) + (pcnt[y] + pcnt[0]) * (scnt[y] + scnt[0]) - pcnt[y] * scnt[y];
        x += pcnt[0] * scnt[0];
        for (int y : p)x = std::max(x, pf[x]);
    }
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