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
    int n;
    std::cin >> n;
    std::vector<i64> a(n);
    for (auto &x : a)
        std::cin >> x;
    i64 cnt1 = ranges::count(a, 1), pos = 0, ans = std::accumulate(a.begin(), a.end(), 0ll) - cnt1;
    if (cnt1 == n - 1) {
        for (auto x : a)
            if (x != 1)
                pos = x / 2;
    } else {
        for (auto x : a)
            if (x != 1)
                pos += x / 2 - 1;
    }
    ans += std::min(cnt1, pos);
    std::cout << (ans >= 3 ? ans : 0) << '\n';
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}