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
    std::vector<pii> info(n);
    for (auto& [a, b] : info)std::cin >> a >> b;
    i64 suma = 0, sumb = 0;
    std::vector<pii> p1, p2, p3;
    for (auto& [a, b] : info) {
        if (a < b)p1.push_back({ a,b });
        if (a == b)p2.push_back({ a,b });
        if (a > b)p3.push_back({ a,b });
        suma += a;
        sumb += b;
    }
    ranges::sort(p1, [&](auto x, auto y) {
        if (x.first == y.first)return x.second > y.second;
        return x.first < y.first;
        });
    ranges::sort(p3, [&](auto x, auto y) {
        if (x.second == y.second) return x.first < y.first;
        return x.second > y.second;
        });
    std::vector<i64> a(1), b(1);
    for (auto [x, y] : p1)a.push_back(x), b.push_back(y);
    for (auto [x, y] : p2)a.push_back(x), b.push_back(y);
    for (auto [x, y] : p3)a.push_back(x), b.push_back(y);
    std::vector<i64> prea(n + 2), preb(n + 2);
    std::vector<i64> sufa(n + 2), sufb(n + 2);
    std::vector<i64> premax(n + 2), sufmax(n + 2);
    for (int i = 1;i <= n;++i) {
        prea[i] = prea[i - 1] + a[i];
        preb[i] = preb[i - 1] + b[i];
        premax[i] = std::max(premax[i - 1], prea[i] - preb[i - 1]);
    }
    for (int i = n;i >= 1;--i) {
        sufa[i] = sufa[i + 1] + a[i];
        sufb[i] = sufb[i + 1] + b[i];
        sufmax[i] = std::max(sufmax[i + 1], sufa[i + 1] - sufb[i]);
    }
    i64 ans = 2e18;
    for (int i = 1;i <= n;++i) {
        if (sumb - b[i] >= suma) {
            i64 tmp = 0;
            tmp = std::max(tmp, premax[i - 1]);
            if (i < n)tmp = std::max(tmp, prea[i - 1] + a[i + 1] - preb[i - 1]);
            tmp = std::max(tmp, (prea[i - 1] - preb[i - 1]) - (sufa[i + 1] - sufb[i + 1]) + sufmax[i + 1]);
            ans = std::min(ans, tmp);
            // std::cout << a[i] << ' ' << b[i] << ' ' << i << ' ' << tmp << '\n';
        }
    }
    if (ans == 2e18)std::cout << -1;
    else std::cout << suma + ans;
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