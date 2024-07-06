#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 1e6 + 10, mod = 998244353;
using i64 = long long;
int a[MAXN], c[MAXN], f[MAXN], sum[MAXN], pre[MAXN], suf[MAXN];

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int n, q;cin >> n >> q;
    for (int i = 1;i <= n;++i)cin >> a[i];
    if (n == 1) {
        while (q--) {
            int l, r;cin >> l >> r;
            cout << 1 << '\n';
        }
        return 0;
    }
    int len = 0;
    sum[1] = 1;
    for (int i = 2;i <= n;++i) {
        c[i] = a[i] - a[i - 1];
        if (i == 2 || c[i] != c[i - 1]) {
            f[i] = 2;
        }
        else f[i] = f[i - 1] + 1;
        sum[i] = sum[i - 1] + f[i];
    }

    return 0;
}