#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<int, int>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 1e6;
const int MAXN = 5e6 + 10;
const int inf = 1e9;
// const int mod = 1e9 + 7;
const int mod = 998244353;

int a[MAXN], c[MAXN];
void solve() {
    int n, p;std::cin >> n >> p;
    for (int i = 1;i <= n;++i)std::cin >> a[i];
    //差分定义
    //离散型导数
    for (int i = 1;i <= n;++i)c[i] = a[i] - a[i - 1];

    //对差分数组作前缀和即可获得原数组
    // for (int i = 1;i <= n;++i)a[i] = a[i - 1] + c[i];

    //在差分数组上进行修改
    // c[4] += 2;
    // for (int i = 1;i <= n;++i)a[i] = a[i - 1] + c[i];

    while (p--) {
        int x, y, z;std::cin >> x >> y >> z;
        c[x] += z, c[y + 1] -= z;
    }
    for (int i = 1;i <= n;++i)a[i] = a[i - 1] + c[i];

    int min = inf;
    for (int i = 1;i <= n;++i)min = std::min(min, a[i]);
    std::cout << min;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t = 1;
    while (t--) {
        solve();
        std::cout << '\n';
    }
    return 0;
}