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
    std::vector<int> h(n);
    for (auto& x : h)std::cin >> x;
    std::vector<a2> limit(n);
    for (auto& [l, r] : limit)std::cin >> l >> r;
    for (int i = n - 2;i >= 0;--i) {
        auto& [l, r] = limit[i];
        if (h[i + 1] == -1) {
            l = std::max(l, limit[i][0] - 1);
            r = std::min(r, limit[i][1]);
        }
        else if (h[i + 1] == 0) {
            l = std::max(l, limit[i][0]);
            r = std::min(r, limit[i][1]);
        }
        else {
            l = std::max(l, limit[i][0] - 1);
            r = std::min(r, limit[i][1] - 1);
        }
        if (r < l) {
            std::cout << -1;
            return;
        }
    }
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