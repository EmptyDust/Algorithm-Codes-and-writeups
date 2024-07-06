#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;
using a3 = std::array<int, 3>;

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int n, k;std::cin >> n >> k;
    std::vector<std::vector<int>> map(n, std::vector<int>(n));
    std::vector<std::vector<int>> vis(n, std::vector<int>(n));
    for (auto& vt : map)for (int& x : vt)std::cin >> x;
    int big = k * k - k * k / 2;
    std::vector<a3> a3s;
    for (int i = 0;i < n;++i)for (int j = 0;j < n;++j)
        a3s.push_back({ map[i][j],i,j });
    std::sort(a3s.begin(), a3s.end());
    for (auto [value, x, y] : a3s) {
        int l = std::max(0, x - k), r = std::min(n - 1, x + k);
        int u = std::max(0, y - k), d = std::min(n - 1, y + k);

    }
    return 0;
}