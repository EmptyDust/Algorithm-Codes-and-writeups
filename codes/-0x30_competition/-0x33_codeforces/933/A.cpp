#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10;
int nums[MAXN], n;
using pt = std::pair<int, int>;

void solve() {
    int n, m, k;std::cin >> n >> m >> k;
    std::vector<int> a(n), b(m);
    for (int i = 0;i < n;++i)std::cin >> a[i];
    for (int i = 0;i < m;++i)std::cin >> b[i];
    int cnt = 0;
    for (int s : a)for (int t : b)if (s + t <= k)cnt++;
    std::cout << cnt;
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