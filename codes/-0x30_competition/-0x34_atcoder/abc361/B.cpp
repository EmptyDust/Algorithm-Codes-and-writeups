#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    std::vector<pii> a(3), b(3);
    for (int i = 0;i < 3;++i)std::cin >> a[i].first;
    for (int i = 0;i < 3;++i)std::cin >> a[i].second;
    for (int i = 0;i < 3;++i)std::cin >> b[i].first;
    for (int i = 0;i < 3;++i)std::cin >> b[i].second;
    for (auto& [l, r] : a)if (l > r)std::swap(l, r);
    for (auto& [l, r] : b)if (l > r)std::swap(l, r);
    std::vector<pii> c(3);
    for (int i = 0;i < 3;++i)c[i].first = std::max(a[i].first, b[i].first);
    for (int i = 0;i < 3;++i)c[i].second = std::min(a[i].second, b[i].second);
    bool f = true;
    for (auto& [l, r] : c) {
        if (l >= r)f = false;
    }
    std::cout << (f ? "Yes" : "No");
    return 0;
}