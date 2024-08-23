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

bool check(int a, int b, int c, int d) {
    int res = 0;
    if (a > c)res++;
    else if (a < c)res--;
    if (b > d)res++;
    else if (b < d)res--;
    return res > 0;
}

void solve() {
    int a, b, c, d;std::cin >> a >> b >> c >> d;
    int ans = check(a, b, c, d) + check(b, a, c, d) + check(a, b, d, c) + check(b, a, d, c);
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