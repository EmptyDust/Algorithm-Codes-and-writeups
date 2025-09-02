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
    int n, q;std::cin >> n >> q;
    std::vector<i64> a(n);
    for (auto& x : a)std::cin >> x;
    ranges::sort(a);
    auto pre(a);
    for (int i = 1;i < a.size();++i) pre[i] += pre[i - 1];
    while (q--) {
        int x;std::cin >> x;
        auto p = std::lower_bound(a.begin(), a.end(), x) - a.begin();
        if (p == n) {
            std::cout << -1 << '\n';
            continue;
        }
        i64 cnt = n - p;
        // std::cout << a[p] << ' ';
        i64 ans = (cnt - 1) * (x - 1) + x;
        if (p) ans += pre[p - 1];
        std::cout << ans << '\n';
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}