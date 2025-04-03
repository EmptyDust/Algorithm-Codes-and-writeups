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
    bool a, b;a = b = false;
    i64 ans = 0;
    for (int i = 30;i >= 0;i--) if (i < std::__lg(n)) {
        int x = n >> i & 1;
        if (!a) {
            if (!x) {
                ans |= 1 << i, a = true;
                // std::cout << i << ' ';
            }
        }
        if (!b) {
            if (x) {
                ans |= 1 << i;
                b = true;
                // std::cout << i << ' ';
            }
        }
    }
    if (!a || !b)std::cout << -1;
    else std::cout << ans;
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