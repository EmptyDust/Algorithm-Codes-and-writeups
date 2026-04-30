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
    int n, q;std::cin >> n >> q;
    std::vector<i64> a(2 * n), pre(2 * n + 1);
    for (int i = 0;i < n;++i) {
        std::cin >> a[i];
        a[i + n] = a[i];
    }
    for (int i = 0;i < 2 * n;++i)
        pre[i + 1] = pre[i] + a[i];

    auto query = [&](i64 x) {
        i64 res = x / n * pre[n];
        i64 st = x / n;
        res += pre[st + x % n] - pre[st];
        return res;
        };
    while (q--) {
        i64 l, r;std::cin >> l >> r;l--;
        std::cout << query(r) - query(l) << '\n';
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t;std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}