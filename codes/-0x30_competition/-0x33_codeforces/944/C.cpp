#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
int nums[MAXN], n;
using pt = std::pair<int, int>;

void solve() {
    int a, b, c, d;
    std::cin >> a >> b >> c >> d;
    if (a > b)std::swap(a, b);
    if (c > d)std::swap(c, d);
    if (a > c) {
        std::swap(a, c);
        std::swap(b, d);
    }
    if (a < c && c < b && b < d)std::cout << "YES";
    else std::cout << "NO";
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