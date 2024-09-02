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
    int n;
    i64 p;
    std::cin >> n >> p;
    std::vector<i64> a(n), b(n), g[n], c(n);
    for (auto& x : a)std::cin >> x;
    for (auto& x : b)std::cin >> x;
    for (int i = 0;i < n;++i) {
        int k;std::cin >> k;
        c[i] = k;
        for (int j = 0;j < k;++j) {
            int x;std::cin >> x;x--;
            g[x].push_back(i);
        }
    }
    std::priority_queue<pii, std::vector<pii>, std::greater<pii>> pq;
    for (int i = 0;i < n;++i)if (!c[i]) {
        pq.push({ a[i],i });
    }
    std::vector<int> ans;
    while (pq.size()) {
        auto [s, u] = pq.top();
        pq.pop();
        if (s > p)break;
        ans.push_back(u);
        p += b[u];
        for (auto v : g[u]) {
            c[v]--;
            if (c[v] == 0)pq.push({ a[v],v });
        }
    }
    std::cout << ans.size() << '\n';
    ranges::sort(ans);
    for (int x : ans)std::cout << x + 1 << ' ';
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