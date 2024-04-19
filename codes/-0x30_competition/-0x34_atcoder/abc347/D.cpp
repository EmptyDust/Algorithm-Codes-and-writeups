#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10;
int nums[MAXN], n;
using pt = std::pair<int, int>;

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int a, b;std::cin >> a >> b;
    int _a = a, _b = b;
    i64 c;std::cin >> c;
    int cnt = std::__popcount(c);
    i64 A = 0, B = 0;
    int s = 0;
    while (a + b > cnt) {
        if (!((c >> s) & 1)) {
            a--, b--;
            A |= (i64)1 << s;
            B |= (i64)1 << s;
        }
        s++;
    }

    while (a-- > 0) {
        A += c & -c;
        c -= c & -c;
    }
    B |= c;

    if (std::__popcount(A) != _a || std::__popcount(B) != _b) {
        std::cout << -1;
        return 0;
    }
    std::cout << A << ' ' << B;
    return 0;
}