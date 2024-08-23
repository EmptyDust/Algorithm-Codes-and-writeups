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

using i128 = __int128;

__int128 read() {
    __int128 x = 0, f = 1;
    char c = getchar();
    while (c < '0' || c>'9') { if (c == '-') f = -1;c = getchar(); }
    while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
    return x * f;
}


void write(__int128 x) {
    if (x < 0) putchar('-'), x = -x;
    if (x > 9) write(x / 10);
    putchar(x % 10 + '0');
}

void solve() {
    i128 k = read(), x = read(), y = read();//std::cin >> k >> x >> y;
    if (x > y)std::swap(x, y);
    bool a = false, b = false;
    // if (x >= k && y >= k)
    //     b = false;
    // if (y < k && x * 2 >= k)
    //     a = false;
    auto xi = k / x;
    for (i128 i = xi;i >= std::max(i128(0), xi - 2);--i) {
        auto xp = i * x;
        auto yp = i * y;
        if (i % 2) {
            if (xp < k && k <= yp + y) {
                b = true;
            }
        }
        else {
            if (xp < k && k <= yp + y) {
                a = true;
                // std::cout << i << ' ';
            }
        }
    }
    // if (xi % 2) {
    //     auto xp = xi * x;
    //     auto yp = xi * y;
    //     if (xp < k && k <= yp + y) {
    //         b = true;
    //     }
    //     xi--;
    //     xp = xi * x;
    //     yp = xi * y;
    //     if (xp < k && k <= yp + y) {
    //         a = true;
    //     }
    // }
    // else {
    //     auto xp = xi * x;
    //     auto yp = xi * y;
    //     if (xp < k && k <= yp + y) {
    //         a = true;
    //     }
    //     xi--;
    //     xp = xi * x;
    //     yp = xi * y;
    //     if (xp < k && k <= yp + y) {
    //         b = true;
    //     }
    // }
    std::cout << (a ? "Yes" : "No") << '\n';
    std::cout << (b ? "Yes" : "No") << '\n';
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t = read();
    while (t--) {
        solve();
    }
    return 0;
}