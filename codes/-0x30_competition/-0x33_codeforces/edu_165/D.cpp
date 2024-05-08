#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pt = std::pair<int, int>;

void solve() {
    int n, k;std::cin >> n >> k;
    std::vector<int> a(n), b(n);
    for (int i = 0;i < n;++i)std::cin >> a[i];
    for (int i = 0;i < n;++i)std::cin >> b[i];
    i64 sum = 0, ans = 0;
    std::vector<pt> ay;
    for (int i = 0;i < n;++i) if (a[i] - b[i] <= 0) {
        ay.push_back({ b[i], a[i] });
        sum += b[i] - a[i];
    }
    std::sort(ay.begin(), ay.end(), std::greater<pt>());
    std::priority_queue<pt> pq;
    for (int i = 0;i < ay.size();++i) {
        int x = ay[i].second;
        int y = ay[i].first;
        if (pq.size() < k) {
            pq.push({ x,y });
            sum -= y;
        }
        else {
            ans = std::max(ans, sum);
            if (pq.size()) {
                auto [curx, cury] = pq.top();
                pq.pop();
                sum += curx;
            }
            pq.push({ x,y });
            sum -= y;
        }
    }
    std::cout << ans << ' ';
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