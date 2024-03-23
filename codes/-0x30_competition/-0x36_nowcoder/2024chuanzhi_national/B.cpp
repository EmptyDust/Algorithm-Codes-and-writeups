#include<bits/stdc++.h>
constexpr int MAXN = 3e5 + 10;
int a[MAXN], b[MAXN], c[MAXN];
using i64 = long long;

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int n;std::cin >> n;
    for (int i = 1;i <= n;++i)std::cin >> a[i];
    for (int i = 1;i <= n;++i)std::cin >> b[i];
    for (int i = 1;i <= n;++i)
        c[i] = c[i - 1] + (a[i] == b[i]);
    int q;std::cin >> q;
    int l, r;
    while (q--) {
        std::cin >> l >> r;
        std::cout << (c[l - 1] == c[r] ? "YES" : "NO") << '\n';
    }
    return 0;
}