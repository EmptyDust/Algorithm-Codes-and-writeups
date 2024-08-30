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
    std::vector<i64> a(n);
    for (auto& x : a)std::cin >> x;
    i64 sum = std::accumulate(a.begin(), a.end(), 0.0);
    double cnt = n;
    double max = sum / cnt;
    int p = std::min_element(a.begin(), a.end()) - a.begin();
    max = std::max(max, std::accumulate(a.begin() + p - 1, a.end(), 0.0) / (n - (p - 1)));
    max = std::max(max, std::accumulate(a.begin(), a.begin() + p + 2, 0.0) / (p + 2));
    std::cout << max;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    std::cout.precision(14);
    int t;std::cin >> t;
    while (t--) {
        solve();
        std::cout << '\n';
    }
    return 0;
}