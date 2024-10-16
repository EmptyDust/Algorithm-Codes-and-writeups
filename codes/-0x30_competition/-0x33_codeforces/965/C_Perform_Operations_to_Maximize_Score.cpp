#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<i64, i64>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
// const int mod = 1e9 + 7;
const int mod = 998244353;

void solve() {
    i64 n, k;std::cin >> n >> k;
    std::vector<pii> a(n);
    for (auto& [x, _] : a)std::cin >> x;
    for (auto& [_, c] : a)std::cin >> c;
    ranges::sort(a);
    i64 ans = *ranges::partition_point(views::iota(0ll, a[n - 2].first + k), [&](i64 x) {
        int cnt = 0;
        i64 cur = k;
        for (int i = n - 2;i >= 0;--i) {
            if (a[i].first >= x) {
                cnt++;
            }
            else if (a[i].second && cur >= x - a[i].first) {
                cur -= x - a[i].first;
                cnt++;
            }
        }
        return cnt * 2 > n - 1;
        }) - 1 + a.back().first;
    for (int i = 0;i < n;++i) {
        i64 mid = (n - 2) / 2;
        mid = i <= mid ? a[mid + 1].first : a[mid].first;
        ans = std::max(ans, a[i].first + mid + a[i].second * k);
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