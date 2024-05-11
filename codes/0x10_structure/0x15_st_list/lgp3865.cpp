#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10;
int nums[MAXN], n, f[MAXN][30], lg[MAXN];
using pt = std::pair<int, int>;

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int n, m;std::cin >> n >> m;
    lg[1] = 0;
    for (int i = 2;i <= n;i++) lg[i] = lg[i >> 1] + 1;
    for (int i = 1;i <= n;++i)std::cin >> f[i][0];
    for (int s = 1;s <= lg[n];++s) {
        for (int i = 1;i <= n;++i) {
            f[i][s] = std::max(f[i][s - 1], f[i + (1 << (s - 1))][s - 1]);
        }
    }
    int x, y;
    for (int i = 0;i < m;++i) {
        std::cin >> x >> y;
        int l = lg[y - x + 1];
        std::cout << std::max(f[x][l], f[y - (1 << l) + 1][l]) << '\n';
    }
    return 0;
}