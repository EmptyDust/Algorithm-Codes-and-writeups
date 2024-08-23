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

void solve() {
    for (int n = 0;n <= 10;++n) {
        int cnt = 0;
        for (int a = 0;a <= n;++a)
            for (int b = 0;b <= n;++b)
                for (int c = 0;c <= n;++c)
                    for (int d = 0;d <= n;++d)
                        if (a + b + c + d == n)
                            cnt++;
        std::cout << cnt << ' ';
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t = 1;
    while (t--) {
        solve();
        std::cout << '\n';
    }
    return 0;
}