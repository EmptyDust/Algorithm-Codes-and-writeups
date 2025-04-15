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
    bool even = false, odd = false;
    for (int i = 0;i < n;++i)if (a[i] % 2 == 0) {
        even = true;
    }
    if (!even) {
        std::cout << ranges::max(a);
        return;
    }
    for (int i = 0;i < n;++i)if (a[i] % 2) {
        odd = true;
    }
    if (!odd) {
        std::cout << ranges::max(a);
        return;
    }
    i64 ans = 1;
    for (int i = 0;i < n;++i) {
        ans += a[i] - a[i] % 2;
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