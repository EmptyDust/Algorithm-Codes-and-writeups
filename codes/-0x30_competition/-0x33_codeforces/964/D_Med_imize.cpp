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
    int n, k;std::cin >> n >> k;
    int m = n % k;
    if (!m)m = k;
    std::vector<int> a(n);
    for (int& x : a)std::cin >> x;
    std::cout << *ranges::partition_point(views::iota(0, ranges::max(a) + 1),
        [&](int x) {
            std::vector<int> f(m + 1, -n);
            f[0] = 0;
            for (int i = 0;i < n;++i) {
                int j = i % k;
                if (j < m)f[j + 1] = std::max(f[j + 1], f[j] + (a[i] >= x ? 1 : -1));
            }
            return f.back() > 0;
        }) - 1 << '\n';
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