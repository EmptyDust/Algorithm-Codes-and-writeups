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
using b10 = std::array<bool, 10>;

const int N = 1e6;
const int MAXN = 1e6 + 10;
const i64 inf = 2e18;
// const int mod = 1e9 + 7;
const int mod = 998244353;

void solve() {
    i64 a;
    int n;
    std::cin >> a >> n;

    b10 vaild = b10();
    int max = -1, min = 10;
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        vaild[x] = 1;
        max = x;
        if (min == 10)
            min = x;
    }

    if (n == 1 && vaild[0] == 1) {
        std::cout << a << '\n';
        return;
    }

    std::vector<int> x;
    auto _a = a;
    while (_a) {
        x.push_back(_a % 10);
        _a /= 10;
    }
    x.push_back(0);
    std::reverse(x.begin(), x.end());
    int m = x.size();

    i64 tmp = 0;
    i64 ans = inf;

    i64 res = 0;
    bool lead0 = 1;
    for (int i = 0; i < m; ++i) {
        int p = x[i];
        if (i == m - 1)
            lead0 = 0;
        for (int j = p + 1; j < 10; ++j)
            if (vaild[j]) {
                tmp = res * 10 + j;
                for (int k = i + 1; k < m; ++k) {
                    tmp = tmp * 10 + min;
                }
                ans = std::min(ans, tmp - a);
                // std::cout << tmp << ' ';
                break;
            }
        for (int j = p - 1; j >= 0; --j)
            if (vaild[j] || j == 0 && lead0) {
                tmp = res * 10 + j;
                for (int k = i + 1; k < m; ++k) {
                    tmp = tmp * 10 + max;
                }
                ans = std::min(ans, a - tmp);
                // std::cout << tmp << ' ';
                break;
            }

        if (p != 0)
            lead0 = 0;

        if (vaild[p]) {
            res = res * 10 + p;
        } else if (lead0)
            continue;
        else
            break;

        if (i == m - 1) {
            ans = 0;
        }
    }

    std::cout << ans << '\n';
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}