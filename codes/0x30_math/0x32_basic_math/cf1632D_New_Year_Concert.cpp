#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;
using a3 = std::array<int, 3>;//gcd l r

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int n;std::cin >> n;
    std::vector<int> a(n);
    std::vector<a3> gcds;
    int cnt = 0;
    for (int i = 1;i <= n;++i) {
        int x;std::cin >> x;
        for (auto& [g, l, r] : gcds)
            g = std::__gcd(x, g);
        gcds.push_back({ x,i,i });
        std::vector<a3> ngcds(1, gcds.front());
        for (int j = 1;j < gcds.size();++j) {
            if (gcds[j][0] == ngcds.back()[0])
                ngcds.back()[2] = gcds[j][2];
            else ngcds.push_back(gcds[j]);
        }
        gcds = ngcds;
        for (auto [g, l, r] : gcds) {
            int llen = i - r + 1, rlen = i - l + 1;
            if (llen <= g && g <= rlen) {
                cnt++;
                gcds.assign(1, { 1,1,i });
                break;
            }
        }
        std::cout << cnt << ' ';
    }
    return 0;
}