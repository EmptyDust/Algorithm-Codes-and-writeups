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
    int n, k;std::cin >> n >> k;
    std::vector<int> a(n + 1);
    for (int i = 1;i <= n;++i)
        std::cin >> a[i];
    auto l = 1, r = n + 1;
    auto check = [&](auto x)->bool {
        // std::cout << x << ' ';
        auto b(a);
        for (int i = 1;i <= n;++i) {
            b[i] = (b[i] >= x ? 1 : -1);
            b[i] += b[i - 1];
        }
        int min = 0, minp = 0;
        for (int i = k;i <= n;++i) {
            if (min > b[i - k]) {
                min = b[i - k];
                minp = i - k;
            }
            if (b[i] >= min) return 0;
        }
        // std::cout << "no";
        return 1;
        };
    while (l < r) {
        auto mid = l + r >> 1;
        if (check(mid))r = mid;
        else l = mid + 1;
    }
    int ans = l - 1;
    std::cout << ans << ' ';

    auto b(a);
    for (int i = 1;i <= n;++i) {
        b[i] = (b[i] >= ans ? 1 : -1);
        b[i] += b[i - 1];
    }
    int min = 0, minp = 0;
    for (int i = k;i <= n;++i) {
        if (min > b[i - k]) {
            min = b[i - k];
            minp = i - k;
        }
        if (b[i] >= min) {
            std::cout << minp + 1 << ' ' << i;
            return;
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