#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;

void solve() {
    int n, k;std::cin >> n >> k;
    if (k == 0) {
        std::cout << 0;
        return;
    }
    std::vector<int> q;q.push_back(n);
    for (int i = n - 1;i >= 1;--i) {
        q.push_back(i);
        q.push_back(i);
    }
    for (int i = 0;i < q.size();++i) {
        if (k <= q[i]) {
            std::cout << i + 1;
            return;
        }
        k -= q[i];
    }
    return;
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