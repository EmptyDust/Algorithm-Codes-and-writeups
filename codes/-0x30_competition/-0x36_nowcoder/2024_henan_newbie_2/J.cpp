#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;

i64 cal(int map[5][5], int n) {
    if (n == 1)return map[0][0];
    i64 res = 0;
    for (int t = 0;t < n;++t) {
        int nmap[5][5];
        memset(nmap, 0, sizeof nmap);
        int curi = 0;
        for (int i = 0;i < n;++i) {
            if (i == t)continue;
            int curj = 0;
            for (int j = 1;j < n;++j) {
                nmap[curi][curj] = map[i][j];
                curj++;
            }
            curi++;
        }

        res += (t % 2 ? -1 : 1) * map[t][0] * cal(nmap, n - 1);
    }
    return res;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int n, m;std::cin >> n >> m;
    int map[5][5];
    memset(map, 0, sizeof map);
    for (int i = 0;i < n;++i)for (int j = 0;j < m;++j) {
        std::cin >> map[i][j];
    }
    i64 ans = 1e18;
    for (int i = 1;i <= std::max(n, m);++i) {
        ans = std::min(ans, cal(map, i));
    }
    std::cout << ans;
    return 0;
}