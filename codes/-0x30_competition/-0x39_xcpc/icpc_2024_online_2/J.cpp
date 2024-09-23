#include<bits/stdc++.h>

using i64 = long long;
using pii = std::pair<int, int>;
using a3 = std::array<i64, 3>;

void solve() {
    int n;std::cin >> n;
    std::vector<a3> a3s(n);
    i64 sumw = 0;
    for (auto& [w, v, c] : a3s)std::cin >> w >> v >> c, sumw += w;
    std::sort(a3s.begin(), a3s.end(), [&](a3 a, a3 b) {
        //if (a[2] == b[2])
        return a[0] * b[2] < b[0] * a[2];
        });
    i64 ans = 0;
    for (auto [w, v, c] : a3s) {
        sumw -= w;
        v -= sumw * c;
        ans += v;
    }
    std::cout << ans;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t = 1;//std::cin >> t;
    while (t--) {
        solve();
        std::cout << '\n';
    }
    return 0;
}