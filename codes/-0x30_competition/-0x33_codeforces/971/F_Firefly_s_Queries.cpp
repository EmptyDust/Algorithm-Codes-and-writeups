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

i64 ceilDiv(i64 n, i64 m) {
    if (n >= 0) {
        return (n + m - 1) / m;
    }
    else {
        return n / m;
    }
}

i64 floorDiv(i64 n, i64 m) {
    if (n >= 0) {
        return n / m;
    }
    else {
        return (n - m + 1) / m;
    }
}

void solve() {
    int n, q;std::cin >> n >> q;
    std::vector<i64> a(n), pre(n), suf(n);
    for (auto& x : a)std::cin >> x;
    i64 sum = std::accumulate(a.begin(), a.end(), 0ll);
    for (int i = 0;i < n;++i)pre[i] = i ? pre[i - 1] + a[i] : a[i];
    for (int i = n - 1;i >= 0;--i)pre[i] = i != n - 1 ? pre[i - 1] + a[i] : a[i];
    while (q--) {
        i64 l, r;std::cin >> l >> r;l--, r--;
        i64 b = r / n - l / n;
        i64 ans = b * sum;
        for (int i = 0;i < r;++i) {
            
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