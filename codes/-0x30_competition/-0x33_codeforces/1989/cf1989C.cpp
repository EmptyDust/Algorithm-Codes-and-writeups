#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;

void solve() {
    int n;std::cin >> n;
    std::vector<int> a(n), b(n);
    for (int& x : a)std::cin >> x;
    for (int& x : b)std::cin >> x;
    int botha = 0, bothm = 0, ax = 0, bx = 0;
    for (int i = 0;i < n;++i) {
        if (a[i] == b[i]) {
            if (a[i] == 1)
                botha++;
            if (a[i] == -1)
                bothm++;
        }
        else if (a[i] > b[i])ax += a[i];
        else bx += b[i];
    }
    if (ax < bx)std::swap(ax, bx);
    int c = ax - bx;
    ax -= std::min(c, bothm);
    bothm -= std::min(c, bothm);
    c = ax - bx;
    bx += std::min(c, botha);
    botha -= std::min(c, botha);

    int both = botha - bothm;
    ax += both / 2;
    bx += both - both / 2;
    std::cout << std::min(ax, bx);
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