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
    int n, k;std::cin >> n >> k;
    std::vector<int> a(n);
    for (auto& x : a)std::cin >> x;
    i64 max = ranges::max(a);
    ranges::sort(a, std::greater<int>());
    i64 ans = 1;
    while (a.size() && a.back() == 0) a.pop_back();
    n = a.size();
    if (n < k) {
        std::cout << max % mod;
        return;
    }
    int y = n - (n - k) % (k - 1);
    for (int i = 0;i < y;++i) ans = ans * a[i] % mod;
    // ans = std::max(ans, max);
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