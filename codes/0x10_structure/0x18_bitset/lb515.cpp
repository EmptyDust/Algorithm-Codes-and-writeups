#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 101, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
int nums[MAXN], n;
using pt = std::pair<int, int>;

std::bitset<N* N* N> f[N];
signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n;
    int a, b;
    f[0][0] = 1;
    for (int i = 1;i <= n;++i) {
        std::cin >> a >> b;
        for (int j = a;j <= b;++j) {
            f[i] |= f[i - 1] << (j * j);
        }
    }
    std::cout << f[n].count();
    return 0;
}