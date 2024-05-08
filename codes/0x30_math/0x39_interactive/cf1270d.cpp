#include <bits/stdc++.h>
using i64 = long long;
#define int long long
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
int n, k, rnms[MAXN], f[MAXN];
using pt = std::pair<int, int>;

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n >> k;
    std::vector<bool> f(n + 1, 1);
    int pos, xf;
    for (int t = 1;t <= n - k + 1;++t) {
        int cnt = 1;std::cout << "? ";
        for (int i = 1;i <= n && cnt <= k;++i)if (f[i]) {
            ++cnt;
            std::cout << i << ' ';
        }
        std::cout << std::endl;
        std::cin >> pos >> xf;
        rnms[pos] = xf;
        f[pos] = 0;
    }
    int x = -1, y = -1;
    for (int i = 1;i <= n && (x == -1 || y == -1);++i)if (!f[i]) {
        if (x == -1)x = i;
        else y = i;
    }
    std::vector<int> ls{ 0 }, res{ 0 };
    for (int i = 1;i <= n;++i)if (f[i])
        ls.push_back(i);
    int ans = 1;
    for (int i = 1;i < k;++i) {
        std::cout << "? ";
        for (int j = 1;j < k;++j)if (i != j)
            std::cout << ls[j] << ' ';
        std::cout << x << ' ' << y << std::endl;
        std::cin >> pos >> xf;
        if (xf == std::max(rnms[x], rnms[y]))ans++;
    }
    std::cout << "! " << ans << std::endl;
    return 0;
}