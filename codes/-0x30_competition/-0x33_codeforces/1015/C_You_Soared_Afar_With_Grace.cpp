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
    std::vector<int> a(n), b(n);
    for (auto& x : a)std::cin >> x;
    for (auto& x : b)std::cin >> x;
    std::vector<int> c(n + 1), d(n + 1);
    int eq = 0;
    for (int i = 0;i < n;++i) {
        int x = a[i], y = b[i];
        if (c[x] && c[x] != y) {
            std::cout << -1 << '\n';
            return;
        }
        if (x == y) {
            eq++;
        }
        c[x] = y, c[y] = x;
        d[x] = i;
    }
    if (eq != n % 2) {
        std::cout << -1 << '\n';
        return;
    }
    std::vector<pii> ans;
    auto swap = [&](int x, int y) {
        if (x == y)return;
        std::swap(d[a[x]], d[a[y]]);
        std::swap(a[x], a[y]);
        ans.push_back({ x + 1,y + 1 });
        };
    if (n % 2) {
        for (int i = 1;i <= n;++i) {
            if (c[i] == i) {
                swap(d[i], n / 2);
                break;
            }
        }
    }
    for (int i = 0;i < n / 2;++i) {
        int j = n - 1 - i;
        int x = a[i];
        // std::cout << i << ' ' << d[c[x]] << '\n';
        if (d[c[x]] != j) {
            swap(d[c[x]], j);
        }
    }
    std::cout << ans.size() << '\n';
    for (auto [x, y] : ans)std::cout << x << " " << y << '\n';
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