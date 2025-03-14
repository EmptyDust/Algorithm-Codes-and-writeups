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
    int n, m;std::cin >> n >> m;
    i64 ans = 0;
    std::vector<int> a(n), b(m);
    for (int& x : a)std::cin >> x;
    for (int& x : b)std::cin >> x;
    for (int i = 1;i < n;++i)ans += std::abs(a[i] - a[i - 1]);
    for (int i = 1;i < m;++i)ans += std::abs(b[i] - b[i - 1]);
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