#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int n;std::cin >> n;
    std::vector<std::vector<int>> map(2, std::vector<int>(n));
    for (int i = 0;i < 2;++i) {
        std::string s;std::cin >> s;
        for (int j = 0;j < n;++j) {
            map[i][j] = s[j] == 'R';
        }
    }
    int ans = 0, res = 0, cnt = 0, pre = -1;
    for (int i = 0;i < n;++i) {
        if (map[0][i] && map[1][i]) {
            res++;
            cnt++;
        }
        else if (map[0][i] || map[1][i]) {
            res++;
            res += cnt;
            if (pre == cnt % 2) {
                cnt--;
            }
            cnt = 0;
            pre = 0;
        }
        else if (map[1][i]) {
            res++;
            res += cnt;
            if (pre != cnt % 2) {
                cnt--;
            }
            cnt = 0;
            pre = 1;
        }
        else {
            res += cnt;
            ans = std::max(ans, res);

            pre = -1;
            cnt = 0;
            res = 0;
        }
        std::cout << i << ' ' << res << '\n';
    }
    res += cnt;
    ans = std::max(ans, res);
    std::cout << ans;
    return 0;
}