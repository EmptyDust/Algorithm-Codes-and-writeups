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
    int A, B, X, Y;
    std::cin >> A >> B >> X >> Y;
    int a = A; if (a) while (a % 2 == 0) a >>= 1;
    int b = B; if (b) while (b % 2 == 0) b >>= 1;
    if (a && X % a || b && Y % b) {
        std::cout << -1;
        return;
    }
    if (a) A /= a, X /= a;
    if (b) B /= b, Y /= b;
    std::vector<a4> ans;
    // std::cout << A << ' ' << B << ' ';
    while (!((0 == X || X == A) && (0 == Y || Y == B))) {
        int tx = A <= X * 2 ? A : 0;
        int ty = B <= Y * 2 ? B : 0;
        int sx = X * 2 - tx;
        int sy = Y * 2 - ty;
        ans.push_back({ tx, ty, sx, sy });
        X = sx;
        Y = sy;
    }
    ranges::reverse(ans);
    std::cout << ans.size() << '\n';
    for (auto [tx, ty, sx, sy] : ans)
        std::cout << tx * a << ' ' << ty * b << ' ' << sx * a << ' ' << sy * b << '\n';
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