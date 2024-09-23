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
    int l, r, L, R;std::cin >> l >> r >> L >> R;
    int ans = 0;
    for (int i = 0;i <= 101;++i) {
        if (l <= i && i <= r && L <= i + 1 && i + 1 <= R ||
            l <= i + 1 && i + 1 <= r && L <= i && i <= R) {
            ans++;
        }
    }
    if (!ans)ans = 1;
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