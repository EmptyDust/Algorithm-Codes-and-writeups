#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using a2 = std::array<int, 2>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
// const int mod = 1e9 + 7;
const int mod = 998244353;

seg

void solve() {
    int n;std::cin >> n;
    std::vector<int> v(n + 1), nv(n + 1), a(n + 1), b(n + 1), rank(n + 1);
    for (int i = 1;i <= n;++i)std::cin >> v[i];
    for (int i = 1;i <= n;++i)std::cin >> a[i];
    for (int i = 1;i <= n;++i)std::cin >> b[i];
    for (int i = 1;i <= n;++i) {
        rank[a[i]] = i;
        nv[i] = v[a[i]];
    }
    for (int i = 1;i <= n;++i) b[i] = rank[b[i]];
    for (int i = 1;i <= n;++i)std::cout << b[i] << ' ';std::cout << '\n';
    for (int i = 1;i <= n;++i)std::cout << nv[i] << ' ';std::cout << '\n';

}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t;std::cin >> t;
    while (t--) {
        solve();
        std::cout << '\n';
    }
    return 0;
}