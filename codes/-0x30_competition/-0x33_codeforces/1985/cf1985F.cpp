#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;
using a3 = std::array<i64, 3>;

void solve() {
    int h, n;std::cin >> h >> n;
    std::vector<int> a(n), b(n);
    for (int& x : a)std::cin >> x;
    for (int& x : b)std::cin >> x;
    std::priority_queue<a3, std::vector<a3>, std::greater<a3>> pq;
    for (int i = 0;i < n;++i) {
        pq.push({ 1,a[i],b[i] });
    }
    while (1) {
        auto [t, d, c] = pq.top();
        pq.pop();
        h -= d;
        pq.push({ t + c,d,c });
        if (h <= 0) {
            std::cout << t;
            return;
        }
    }
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