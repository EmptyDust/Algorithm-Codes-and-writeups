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
    int n, k, q;std::cin >> n >> k >> q;
    std::vector<int> ans(n + 1, k);
    std::vector<a2> K_1;
    for (int _ = 0;_ < q;++_) {
        int c, l, r;std::cin >> c >> l >> r;
        if (c == 1) {
            K_1.push_back({ l, r });
        }
        else {
            for (int i = l;i <= r;++i) ans[i] = -1;
        }
    }
    for (auto [l, r] : K_1) {
        for (int i = l;i <= r;++i) {
            if (ans[i] == -1) ans[i] = k + 1;
        }
    }
    for (int i = 1;i <= n;++i) {
        if (ans[i] == -1)ans[i] = i % k;
        std::cout << ans[i] << ' ';
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