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

i64 qpow(i64 x, i64 p) {
    i64 ret = 1;
    while (p) {
        if (p & 1)ret = ret * x;
        p >>= 1;
        x = x * x;
    }
    return ret;
}

void solve() {
    int r, c, x;std::cin >> r >> c >> x;
    std::vector map(r, std::vector<int>(c));
    for (int i = 0;i < r;++i) {
        std::string s;std::cin >> s;
        for (int j = 0;j < c;++j) {
            map[i][j] = s[j] - '0';
        }
    }
    int q;std::cin >> q;
    if (x == 1) {
        while (q--) {
            int ax, ay, bx, by;
            std::cin >> ax >> ay >> bx >> by;
            ax--, ay--, bx--, by--;
            std::cout << map[ax][ay] - map[bx][by] << '\n';
        }
        return;
    }
    std::vector height(r, std::vector<i64>(c));
    for (int i = 0;i < r;++i) {
        for (int j = 0;j < c;++j) {
            if (i && j) {
                i64 a = height[i - 1][j] + qpow(map[i][j] - map[i - 1][j], x);
                i64 b = height[i][j - 1] + qpow(map[i][j] - map[i][j - 1], x);
                if (a != b) {
                    while (q--)std::cout << "INVALID" << '\n';
                    return;
                }
                height[i][j] = a;
            }
            else if (i) {
                i64 a = height[i - 1][j] + qpow(map[i][j] - map[i - 1][j], x);
                height[i][j] = a;
            }
            else if (j) {
                i64 b = height[i][j - 1] + qpow(map[i][j] - map[i][j - 1], x);
                height[i][j] = b;
            }
        }
    }
    while (q--) {
        int ax, ay, bx, by;
        std::cin >> ax >> ay >> bx >> by;
        ax--, ay--, bx--, by--;
        std::cout << height[ax][ay] - height[bx][by] << '\n';
    }
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