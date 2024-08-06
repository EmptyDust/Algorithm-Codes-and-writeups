#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;

std::vector<int> ys[MAXN];
void init() {
    for (i64 i = 1;i <= N;++i) {
        for (i64 j = i;j <= N;j += i) {
            ys[j].push_back(i);
        }
    }
}

void solve() {
    i64 n, x;std::cin >> n >> x;
    i64 ans = 0;
    for (int ab = 1;ab <= n;++ab) {
        for (int a : ys[ab]) {
            int b = ab / a;
            //c<=x-a-b
            //c<=(n-ab)/(a+b)
            int c = std::min(x - a - b, (n - ab) / (a + b));
            if (c > 0) {
                ans += c;
            }
        }
    }
    std::cout << ans;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    init();
    int t;std::cin >> t;
    while (t--) {
        solve();
        std::cout << '\n';
    }
    return 0;
}