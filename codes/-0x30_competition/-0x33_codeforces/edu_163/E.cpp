#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10;
int nums[MAXN], n, k;
using pt = std::pair<int, int>;

void solve() {
    std::cin >> n >> k;
    int t = n / k;
    int y = n % k;
    int q = t + (y > 0);
    for (int i = 0;i < t;++i) {
        for (int j = k / 2 + 1;j <= k;++j)std::cout << j + i * k << ' ';
        for (int j = 1;j <= k / 2;++j)std::cout << j + i * k << ' ';
    }
    if (y) {
        for (int j = y / 2 + 1;j <= y;++j)std::cout << j + t * k << ' ';
        for (int j = 1;j <= y / 2;++j)std::cout << j + t * k << ' ';
    }
    std::cout << '\n' << q << '\n';
    for (int i = 0;i < t;++i)for (int j = 0;j < k;++j)std::cout << i + 1 << ' ';
    for (int i = 0;i < y;++i)std::cout << t + 1 << ' ';
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