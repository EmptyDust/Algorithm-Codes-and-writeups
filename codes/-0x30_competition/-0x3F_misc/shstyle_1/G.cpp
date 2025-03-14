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
//1011
//1111
void solve() {
    i64 a, b;std::cin >> a >> b;
    i64 ans = 0;
    bool ok = true;
    for (int i = 61;i >= 0;i--) {
        i64 A = a >> i & 1;
        i64 B = b >> i & 1;
        if (A == B && ok) ans |= A << i;
        else {
            ok = false;
            if (A) {
                ans |= 1ll << i;
                // std::cout << ans << ' ';
                if (ans < a)ans += 1ll << i;
                break;
            }
        }
    }
    std::cout << ans;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t = 1;//std::cin >> t;
    while (t--) {
        solve();
        std::cout << '\n';
    }
    return 0;
}