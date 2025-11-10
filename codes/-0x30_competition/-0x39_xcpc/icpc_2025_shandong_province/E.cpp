#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using u128 = unsigned __int128;

using a2 = std::array<int, 2>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
// const int mod = 1e9 + 7;
const int mod = 998244353;

void solve() {
    i64 n, k;std::cin >> n >> k;
    std::vector<i64> a(n + 1), presum(n + 1);
    for (int i = 1;i <= n;++i)std::cin >> a[i];
    ranges::sort(a);
    for (int i = 1;i <= n;++i) presum[i] += presum[i - 1] + a[i];
    i64 sum = std::accumulate(a.begin(), a.end(), 0ll) + k;
    i64 max = ranges::max(a);
    std::vector<int> p(max + 3), yz;
    for (i64 i = 1;i <= std::sqrtl(sum);++i) {
        yz.push_back(i);
        if (i != sum / i) yz.push_back(sum / i);
    }
    ranges::sort(yz);
    i64 ans = 1;
    for (auto x : yz) {
        i64 need = 0, last = 1;
        if (max / x == 0) p[last] = n;
        for (int i = 1;i <= max / x + 1 && p[i] != n;++i) {
            for (int t = (1 << std::__lg(n - p[i] + 1));t > 0;t >>= 1) {
                if (p[i] + t <= n && i * x >= a[p[i] + t]) p[i] += t;
            }
            // while (p[i] + 1 <= n && i * x >= a[p[i] + 1]) p[i]++;
            // std::cout << i << ' ' << x << ' ';
            // std::cout << 1ll * i * x * (p[i] - p[i - 1]) - (presum[p[i]] - presum[p[i - 1]]) << ' ';
            // std::cout << p[i] << ' ' << a[p[i]] << '\n';
            need += 1ll * i * x * (p[i] - p[i - 1]) - (presum[p[i]] - presum[p[i - 1]]);
            last = i + 1;
            p[i + 1] = std::max(p[i + 1], p[i]);
        }
        // std::cout << last << ' ';
        assert(p[last] == n);
        need += 1ll * last * x * (p[last] - p[last - 1]) - (presum[p[last]] - presum[p[last - 1]]);
        // std::cout << '\n';
        // std::cout << x << ' ' << need << '\n';
        if (k >= need && (k - need) % x == 0) {
            ans = x;
        }
    }
    std::cout << ans;
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