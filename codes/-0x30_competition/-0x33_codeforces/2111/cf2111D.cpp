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
    std::vector<int> a(m);
    for (auto& x : a)std::cin >> x;
    ranges::sort(a);
    // for (auto x : a)std::cout << x << ' ';
    for (int i = 0, j = m - 1;i <= j && n > 0;++i, --j, n -= 2) {
        for (int k = 0;k < 6;++k)std::cout << (k % 2 ? a[i] : a[j]) << ' ';
        std::cout << '\n';
        if (n > 1) {
            for (int k = 0;k < 6;++k)std::cout << (k % 2 ? a[j] : a[i]) << ' ';
            std::cout << '\n';
        }
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