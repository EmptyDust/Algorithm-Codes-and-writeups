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
    int n;std::cin >> n;
    std::vector<i64> a(n);
    for (auto& x : a)std::cin >> x;
    for (int i = 1;i < 2 * n;++i) {
        a[i] = a[i - 1] + a[i] * (i % 2 ? -1 : 1);
    }
    i64 omax = 0, emax = 0, ans = -1e18, res = a.back();
    for (int i = 0;i < 2 * n;++i) {
        if (i % 2) {
            ans = std::max(ans, res + (omax - a[i]) * 2);
            omax = std::max(omax, a[i]);
        }
        else {
            ans = std::max(ans, res + (emax - a[i]) * 2);
            emax = std::max(emax, a[i]);
        }
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