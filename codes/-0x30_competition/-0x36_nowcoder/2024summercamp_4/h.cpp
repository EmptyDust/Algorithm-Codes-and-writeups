#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;

#define int long long
void solve() {
    int n;std::cin >> n;
    std::vector<int> a(n), c;
    for (int& x : a)std::cin >> x;
    bool ok = true;
    for (int i = 1;i < n;++i)if (a[i] != a[i - 1]) {
        ok = false;
        break;
    }
    if (ok) {
        std::cout << 0;
        return;
    }
    std::sort(a.begin(), a.end());
    for (int i = 1;i < n;++i)c.push_back(a[i] - a[i - 1]);
    int gcd = c[0];
    for (int x : c)gcd = std::__gcd(gcd, x);
    std::cout << gcd;
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