#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10;
int f[MAXN][30], lg[MAXN], n, cnt[MAXN];
using pt = std::pair<int, int>;

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n;
    lg[1] = 0;
    for (int i = 2;i <= n;i++) lg[i] = lg[i >> 1] + 1;
    for (int i = 1;i <= n;++i)std::cin >> f[i][0], cnt[i] = cnt[i - 1] + (f[i][0] == 1);
    for (int s = 1;s <= lg[n];++s) {
        for (int i = 1;i <= n;++i) {
            if (i + (1 << (s - 1)) <= n)
                f[i][s] = std::__gcd(f[i][s - 1], f[i + (1 << (s - 1))][s - 1]);
            else
                f[i][s] = 1;
        }
    }
    int ans = 1e9;
    for (int i = 1;i <= n;++i) {
        int gcd = f[i][0], x = i;
        for (int s = lg[n];~s;--s) {
            if (std::__gcd(gcd, f[x][s]) != 1) {
                gcd = std::__gcd(gcd, f[x][s]);
                x += 1 << s;
            }
        }
        if (std::__gcd(gcd, f[x][0]) == 1) {
            ans = std::min(ans, n - 1 + x - i - (cnt[n] - cnt[x] + cnt[i - 1]));
        }
    }
    std::cout << (ans == 1e9 ? -1 : ans);
    return 0;
}