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
    std::vector<int> a(n);
    for (auto& x : a)std::cin >> x;
    i64 ans = 0;
    for (int i = 0;i < n;++i) {
        int must = 0, all = (1 << m) - 1;
        if (i) {
            must |= (a[i] | a[i - 1]) ^ a[i - 1];
            all &= a[i] | a[i - 1];
        }
        if (i < n - 1) {
            must |= (a[i] | a[i + 1]) ^ a[i + 1];
            all &= a[i] | a[i + 1];
        }
        int cnt = std::__popcount(must ^ all);
        ans += (1 << cnt) - 1;
        // std::cout << (1 << cnt) - 1 << ' ';
    }
    std::cout << ans;
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