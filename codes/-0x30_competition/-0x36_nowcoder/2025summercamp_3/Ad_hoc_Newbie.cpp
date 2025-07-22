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

/*
1 1 1 1 5 1 7

0 0 0 0 2 0 0
0 0 0 0 3 0 0
0 0 0 0 4 0 0
0 0 0 0 0 0 0
2 3 4 0 1 0 0
0 0 0 0 0 0 0
0 6 5 4 3 2 1
*/

void solve() {
    int n;std::cin >> n;
    std::vector<int> a(n);
    for (auto& x : a)std::cin >> x;
    std::vector ans(n, std::vector<int>(n));
    for (int i = 0;i < n;++i) {
        for (int j = 2;j < a[i];++j) {
            ans[i][j - 2] = j;
            ans[j - 2][i] = j;
        }
        if (a[i] != 1) ans[i][i] = 1;
    }
    for (int i = 0;i < n;++i) {
        for (int j = 0;j < n;++j) {
            std::cout << ans[i][j] << ' ';
        }
        std::cout << '\n';
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t;std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}