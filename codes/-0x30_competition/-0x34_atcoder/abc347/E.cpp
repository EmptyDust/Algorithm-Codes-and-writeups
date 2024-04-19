#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10;
int nums[MAXN], n;
using pt = std::pair<int, int>;

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int n, q;std::cin >> n >> q;
    std::vector<i64> qrys(q + 1), f(q + 1), st(n + 1, -1), ans(n + 1, 0);
    for (int i = 1;i <= q;++i)std::cin >> qrys[i];
    int size = 0;
    for (int i = 1;i <= q;++i) {
        int cur = qrys[i];
        if (~st[cur]) {
            ans[cur] += f[i - 1] - f[st[cur] - 1];
            st[cur] = -1;
            size--;
        }
        else {
            size++;
            st[cur] = i;
        }
        f[i] = f[i - 1] + size;
    }
    for (int i = 1;i <= n;++i)if (~st[i])
        ans[i] += f[q] - f[st[i] - 1];
    for (int i = 1;i <= n;++i)std::cout << ans[i] << ' ';
    return 0;
}