#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;

void solve() {
    i64 n, a, b;
    std::cin >> n >> a >> b;
    std::vector<int> A(n);
    for (int& x : A)std::cin >> x;
    i64 odd = 0, even = 0;
    for (int x : A) {
        if (x % 2)odd++;
        else even++;
    }
    i64 ans = 0;
    if (a <= 0 && b <= 0) {
        ans = (odd * (odd - 1) / 2 + even * (even - 1) / 2) * a + even * odd * b;
    }
    else if (a <= 0) {
        ans = (odd * (odd - 1) / 2 + even * (even - 1) / 2) * a;
        if (odd && even)ans += b;
    }
    else if (!odd || !even) {
        ans = (n - 1) * a;
    }
    else if (b <= 0) {
        ans = odd * even * b;
    }
    else {
        ans = std::min((odd - 1 + even - 1) * a + b, (odd + even - 1) * b);
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