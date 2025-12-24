#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using u128 = unsigned __int128;

using a2 = std::array<int, 2>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
// const int mod = 1e9 + 7;
const int mod = 998244353;

void solve() {
    int n, m;std::cin >> n >> m;
    std::vector<int> a(n), d(n);
    for (auto& x : a)std::cin >> x;
    if (n == 1) {
        std::cout << a[0];
        return;
    }
    for (int i = 0;i < m;++i) {
        int u, v;std::cin >> u >> v;
        u--, v--;
        d[u]++;
        d[v]++;
    }
    int ans = 0, max0 = 0, max1 = 0;
    for (int i = 0;i < n;++i) {
        if (d[i] > 1) ans = std::max(ans, a[i]);
        else if (a[i] > max0) max1 = max0, max0 = a[i];
        else if (a[i] > max1) max1 = a[i];
    }
    ans = std::max(ans, max1);
    std::cout << ans;
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