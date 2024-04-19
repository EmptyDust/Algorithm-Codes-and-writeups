#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10;
int nums[MAXN], n;
using pt = std::pair<int, int>;

void solve() {
    int a, b, c;std::cin >> a >> b >> c;
    if (a < b && b < c)std::cout << "STAIR";
    else if (b > a && b > c)std::cout << "PEAK";
    else std::cout << "NONE";
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