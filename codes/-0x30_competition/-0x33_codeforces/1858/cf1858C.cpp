#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10;
using pt = std::pair<int, int>;
//1 2 3 4 8 5 10 6 9 7
//1 1 1 4 1 5 2  3 1    5
//1 2 4 8 3 6 5 10 7 9
//1 2 4 1 3 1 5 1  1 1  5
void solve() {
    int n;std::cin >> n;
    std::vector<int> nums(n + 1);
    for (int i = 1;i <= n;++i)if (!nums[i]) {
        for (int j = i;j <= n;j <<= 1) {
            std::cout << j << ' ';
            nums[j] = 1;
        }
    }
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