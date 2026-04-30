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
    i64 n, k;std::cin >> n >> k;
    std::vector<i64> a(n);
    for (auto& x : a)std::cin >> x;
    i64 max = *std::max_element(a.begin(), a.end());
    i64 sum = std::accumulate(a.begin(), a.end(), 0ll);
    i64 ans = 0;
    for (int i = n;i >= 1;--i) {
        i64 maxcnt = (sum + k) / i;
        if (max > maxcnt)continue;
        if (maxcnt * i < sum)continue;
        ans = i;
        break;
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