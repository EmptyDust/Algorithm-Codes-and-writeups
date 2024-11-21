#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<int, int>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
// const int mod = 1e9 + 7;
const int mod = 998244353;

void solve() {
    int n;std::cin >> n;
    std::vector<i64> a(n);
    for (auto& x : a)std::cin >> x;
    i64 sum = std::accumulate(a.begin(), a.end(), 0ll);
    i64 l = 1, r = sum / n + 1;
    auto check = [&](auto x)->bool {
        std::vector<i64> b(a);
        for (int j = 0;j < 31;++j)
            for (int i = 0;i < n;++i) if (b[i] > x) {
                b[(i + 1) % n] += (b[i] - x) / 2;
                b[i] -= (b[i] - x) / 2 * 2;
            }
        bool ok = true;
        for (int i = 0;i < n;++i) {
            if (b[i] != b[0])ok = false;
            // std::cout << b[i] << ' ' << x << '\n';
        }
        return !ok;
        };
    // for (int i = 0;i < 100;++i) {
    //     std::cout << check(i) << ' ';
    // }
    if (check(0)) {
        std::cout << -1;
        return;
    }
    while (l < r) {
        auto mid = l + r >> 1;
        if (check(mid))r = mid;
        else l = mid + 1;
    }
    // std::cout << l - 1 << ' ';
    std::cout << sum - n * (l - 1);
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