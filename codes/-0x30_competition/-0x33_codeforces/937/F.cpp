#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10;
using pt = std::pair<int, int>;
int a, b, c;

int get_r(int x) {
    int ret = 0;
    for (int i = 0;i < x;++i) {
        if (a) ret += 2, a--;
        else if (b) ret++, b--;
        else c--;
    }
    return ret;
}

int solve() {
    std::cin >> a >> b >> c;
    if (2 * a + b != a + b + c - 1)return -1;
    int x = get_r(1);
    int cnt = 0;
    while (a || b || c) {
        x = get_r(x);
        cnt++;
    }
    return cnt;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t;std::cin >> t;
    while (t--) {
        std::cout << solve();
        std::cout << '\n';
    }
    return 0;
}