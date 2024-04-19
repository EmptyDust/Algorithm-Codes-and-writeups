#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10;
int nums[MAXN], n;
using pt = std::pair<int, int>;

void solve() {
    int a, b, c, d;std::cin >> a >> b >> c >> d;
    i64 ans = d / 2;
    i64 ans1 = a / 2 + b / 2 + c / 2;//全部为偶数
    i64 ans2 = 0;
    if (a > 0 && b > 0 && c > 0) {
        ans2 = 1 + (a - 1) / 2 + (b - 1) / 2 + (c - 1) / 2;
    }
    std::cout << std::max(ans + ans1, ans + ans2);
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