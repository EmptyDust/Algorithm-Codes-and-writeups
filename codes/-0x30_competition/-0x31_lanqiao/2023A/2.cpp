#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10;
int nums[MAXN], n;
using pt = std::pair<int, int>;

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    std::vector<std::vector<i64>> f(31, std::vector<i64>(11, 0));
    f[0][0] = 1;
    for (int i = 1;i <= 30;++i) {
        for (int j = 1;j <= 10;++j) {
            f[i][j] += f[i - 1][j - 1];
            f[i][0] += f[i - 1][j - 1];
        }
    }
    i64 res = 0;
    for (int i = 1;i <= 30;++i)res += f[i][7];
    std::cout << res;
    return 0;
}