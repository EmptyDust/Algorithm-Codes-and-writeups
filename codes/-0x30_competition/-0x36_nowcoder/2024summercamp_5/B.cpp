#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;

bool solve() {
    int n, m, a, b;std::cin >> n >> m >> a >> b;
    if (n > m)std::swap(n, m);
    if (n == 1 && m == 2) {
        return true;
    }
    if (n % 2 && m % 2)return false;
    if (a && b) {
        return true;
    }
    if (b) {
        if (n == 2)return true;
        if (n % 2 == 0 && m % 2 == 0)return true;
        return false;
    }
    if (a) {
        if (n == 1)return true;
        return false;
    }
    return false;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t;std::cin >> t;
    while (t--) {
        std::cout << (solve() ? "Yes" : "No");
        std::cout << '\n';
    }
    return 0;
}