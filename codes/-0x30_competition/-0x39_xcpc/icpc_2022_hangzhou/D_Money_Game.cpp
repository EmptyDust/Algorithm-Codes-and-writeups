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
    std::vector<int> a(n);
    for (int& x : a)std::cin >> x;
    i64 sum = std::accumulate(a.begin(), a.end(), 0ll);
    double one = 1.0 * sum / (n + 1);
    for (int i = 0;i < n;++i) {
        std::cout << one * ((i == 0) + 1) << ' ';
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    std::cout.precision(10);
    int t = 1;
    while (t--) {
        solve();
        std::cout << '\n';
    }
    return 0;
}