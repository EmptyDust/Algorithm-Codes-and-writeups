#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int n, l, r;std::cin >> n >> l >> r;
    std::vector<i64> h(n + 1), sum(n + 1);
    for (int i = 1;i <= n;++i) {
        std::cin >> h[i];
        h[i] = (h[i] - 1) / 2;
    }

    std::sort(h.begin(), h.end());
    for (int i = 1;i <= n;++i)
        sum[i] = sum[i - 1] + h[i];

    std::function<i64(int, int)> get_res = [&](int n, int x) {
        if (x == 1)return sum[n];
        auto res = get_res(n - 1, x - 1);
        if (h[n] > res) {
            return res;
        }
        else {
            return sum[n] / x;
        }
        };
    auto t = get_res(n, l);
    std::cout << (r + t * (r - l) >= n ? "Yes" : "No");
    return 0;
}