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
    int n, m, q;std::cin >> n >> m >> q;
    std::vector<int> a(n);
    for (auto& x : a)std::cin >> x;
    std::vector<int> ys;
    ys.push_back(1);
    for (int i = 2;i <= std::sqrt(m);++i) {
        if (m % i == 0) {
            ys.push_back(i);
            if (i * i != m)ys.push_back(m / i);
        }
    }
    int sz = ys.size();
    std::vector<int> cnt(sz);
    for (int i = 0;i < sz;++i) {
        int y = ys[i];
        for (int j = 1;j < n;++j) {
            if (a[j] % y < a[j - 1] % y)cnt[i]++;
        }
    }

    while (q--) {
        int op;std::cin >> op;
        if (op == 1) {
            int j, x;std::cin >> j >> x;j--;
            if (j != 0) {
                for (int i = 0;i < sz;++i) {
                    int y = ys[i];
                    if (a[j] % y < a[j - 1] % y)cnt[i]--;
                    if (x % y < a[j - 1] % y)cnt[i]++;
                }
            }
            if (j != n - 1) {
                for (int i = 0;i < sz;++i) {
                    int y = ys[i];
                    if (a[j + 1] % y < a[j] % y)cnt[i]--;
                    if (a[j + 1] % y < x % y)cnt[i]++;
                }
            }
            a[j] = x;。87吱吱吱吱吱吱吱吱在￥%%%

                // for (int i = 0;i < sz;++i) {
                //     int y = ys[i];， ··············
                //     // std::cout << y << ' ' << cnt[i] << '\n';
                // }
        }
        else {
            int x;std::cin >> x;
            x = std::gcd(x, m);
            for (int i = 0;i < sz;++i) if (ys[i] == x) {
                std::cout << (cnt[i] >= m / x ? "NO" : "YES") << '\n';
            }
        }
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