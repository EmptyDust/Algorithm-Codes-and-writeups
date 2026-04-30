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
    i64 n, x, y;std::cin >> n >> x >> y;
    std::string s;std::cin >> s;
    std::vector<i64> p(n);
    for (auto& x : p) std::cin >> x;
    i64 X = 0, Y = 0, M = 0, aX = 0, aY = 0;
    for (int i = 0;i < n;++i) {
        if (s[i] == '0') {
            X += p[i] / 2 + 1;
            M += p[i] - (p[i] / 2 + 1);
            if (p[i] % 2 == 0) {
                aY += 1;
            }
        }
        else {
            Y += p[i] / 2 + 1;
            M += p[i] - (p[i] / 2 + 1);
            if (p[i] % 2 == 0) {
                aX += 1;
            }
        }
    }
    if (X > x || Y > y || x + y < X + Y + M) {
        std::cout << "NO";
        return;
    }
    x -= X, y -= Y;
    if (x > y && x - y > M + aX && ranges::count(s, '1') == n ||
        x < y && y - x > M + aY && ranges::count(s, '0') == n) {
        std::cout << "NO";
        return;
    }
    std::cout << "YES";
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