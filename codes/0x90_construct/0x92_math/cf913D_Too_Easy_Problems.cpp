#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<int, int>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
// const int mod = 1e9 + 7;
const int mod = 998244353;

void solve() {
    int n, T;std::cin >> n >> T;
    std::vector<int> a(n), t(n);
    for (int i = 0;i < n;++i)std::cin >> a[i] >> t[i];
    std::vector<int> p(n);
    std::iota(p.begin(), p.end(), 0);
    std::sort(p.begin(), p.end(), [&](int x, int y) {return a[x] > a[y];});
    std::priority_queue<int> pq;
    int ans = 0, tot = 0;
    for (int x : p) {
        pq.push(t[x]);
        tot += t[x];
        if (tot > T) {
            tot -= pq.top();
            pq.pop();
        }
        ans = std::max(ans, std::min(a[x], (int)pq.size()));
    }
    std::cout << ans << "\n";
    std::cout << ans << "\n";
    int cnt = 0;
    std::sort(p.begin(), p.end(), [&](int x, int y) {return t[x] < t[y];});
    for (int x : p) {
        if (a[x] >= ans && cnt < ans) {
            cnt++;
            std::cout << x + 1 << ' ';
        }
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t = 1;
    while (t--) {
        solve();
        std::cout << '\n';
    }
    return 0;
}