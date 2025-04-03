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
    std::vector<i64> a(n);
    for (auto& x : a)std::cin >> x;
    i64 sum = std::accumulate(a.begin(), a.end(), 0ll);
    std::vector<i64> pos(sum + 1);
    pos[0] = 1;
    for (auto x : a)for (int i = sum - x;i >= 0;--i)if (pos[i]) {
        pos[i + x] = 1;
    }
    i64 ans = 0;
    for (int i = 0;i <= sum;++i)if (pos[i]) {
        ans = std::max(ans, 1ll * i * (sum - i));
    }
    std::cout << ans;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    // int t;std::cin >> t;
    int t = 1;
    while (t--) {
        solve();
        std::cout << '\n';
    }
    return 0;
}