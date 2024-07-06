#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;

void solve() {
    int n, m;std::cin >> n >> m;
    std::vector<int> ind(m);
    std::string s;std::cin >> s;
    for (int& x : ind)std::cin >> x;
    std::string c;std::cin >> c;
    std::sort(ind.begin(), ind.end());
    ind.erase(std::unique(ind.begin(), ind.end()), ind.end());
    std::sort(c.begin(), c.end());
    for (int i = 0;i < ind.size();++i) {
        s[ind[i] - 1] = c[i];
    }
    std::cout << s;
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