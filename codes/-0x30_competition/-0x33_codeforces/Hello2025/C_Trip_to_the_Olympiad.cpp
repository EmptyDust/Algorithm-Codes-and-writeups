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
    int l, r;std::cin >> l >> r;
    int add = 0;
    for (int i = 30 - 1;i >= 0;--i) {
        int L = l >> i & 1;
        int R = r >> i & 1;
        if (L && R)add += 1 << i;
        if (R && !L) {
            int ans1 = (add | 1 << i);
            int ans2 = add | ((1 << i) - 1);
            int ans3 = -1;
            for (int i = l;i <= r;++i) {
                if (i != ans1 && i != ans2) {
                    ans3 = i;
                    break;
                }
            }
            std::cout << ans1 << ' ' << ans2 << ' ' << ans3 << '\n';
            return;
        }
    }
    std::cout << l << ' ' << l << ' ' << l << '\n';
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t;std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}