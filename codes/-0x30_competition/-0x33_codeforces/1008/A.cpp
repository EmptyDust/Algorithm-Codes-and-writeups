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
const int MAXN = 1e6 + 10;
const int inf = 1e9;
// const int mod = 1e9 + 7;
const int mod = 998244353;

void solve() {
    int n;std::cin >> n;
    std::vector<i64> b(2 * n), a(2 * n + 1);
    for (auto& x : b)std::cin >> x;
    ranges::sort(b);
    for (int i = 0, j = 3;i < n - 1;++i, j += 2) {
        a[j] = b[i];
    }
    for (int i = n - 1, j = 0;i < 2 * n;++i, j += 2) {
        a[j] = b[i];
    }
    a[1] = a[0];
    for (int i = 2;i < 2 * n + 1;++i) {
        if (i % 2) a[1] -= a[i];
        else a[1] += a[i];
    }
    for (i64& x : a)std::cout << x << " ";
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