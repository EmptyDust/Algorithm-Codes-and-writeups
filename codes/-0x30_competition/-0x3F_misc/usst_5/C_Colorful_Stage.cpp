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
    std::vector<int> a(n), b(n), c(n);
    for (auto& x : a)std::cin >> x;
    for (auto& x : b)std::cin >> x;
    for (int i = 0;i < n;++i)
        c[i] = ((b[i] - a[i]) % m + m) % m;
    c.push_back(0);
    c.push_back(m);
    ranges::sort(c);
    int max = 0;
    for (int i = 1;i < c.size();++i) {
        max = std::max(max, c[i] - c[i - 1]);
    }
    std::cout << m - max;
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