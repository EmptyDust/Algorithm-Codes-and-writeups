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
    while (q--) {
        std::string s;std::cin >> s;
        if (s == "->") {
            int x, y;std::cin >> x >> y; x--, y--;
            i64 res = 0;
            for (int i = n;i > 0;--i) {
                int mid = 1 << i - 1;
                if (x < mid && y < mid) {
                    continue;
                }
                else if (x < mid) {
                    res += 3 * (1ll << i - 1) * (1ll << i - 1);
                }
                else if (y < mid) {
                    res += 2 * (1ll << i - 1) * (1ll << i - 1);
                }
                else {
                    res += (1ll << i - 1) * (1ll << i - 1);
                }
                x %= mid;
                y %= mid;
                // std::cout << res << " " << x << " " << y << '\n';
            }
            std::cout << res + 1 << '\n';
        }
        else {
            i64 x; std::cin >> x;x--;
            int px = 0, py = 0;
            for (int i = n;i > 0;--i) {
                i64 mid = 1ll << (i - 1) * 2;
                int add = 1 << i - 1;
                if (x < mid) {
                    continue;
                }
                else if (x < 2 * mid) {
                    px += add;
                    py += add;
                }
                else if (x < 3 * mid) {
                    px += add;
                }
                else {
                    py += add;
                }
                x %= mid;
            }
            std::cout << px + 1 << " " << py + 1 << "\n";
        }
    }
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