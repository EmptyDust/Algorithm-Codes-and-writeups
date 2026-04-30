#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<int, int>;
using a2 = std::array<i64, 2>;
using a3 = std::array<i64, 3>;
using a4 = std::array<i64, 4>;

const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
// const int mod = 1e9 + 7;
const int mod = 998244353;

i64 cal(i64 len, i64 p, i64 k) {
    return std::min({ k, len - k + 1, p, len - p + 1 });
}

void solve() {
    i64 n, m, k;std::cin >> n >> m >> k;
    i64 w;std::cin >> w;
    std::vector<i64> wei(w);
    for (auto& x : wei)std::cin >> x;
    ranges::sort(wei);
    std::priority_queue<a4> pq;
    i64 midn = (n + 1) / 2;
    for (int i = 1;i <= m;++i) {
        i64 c = cal(n, midn, k);
        i64 d = cal(m, i, k);
        if (n % 2)
            pq.push({ c * d,midn,i,0 });
        else {
            pq.push({ c * d,midn,i,1 });
            pq.push({ c * d,midn + 1,i,-1 });
        }
    }
    i64 ans = 0;
    while (w && pq.size()) {
        auto [add, x, y, op] = pq.top();
        pq.pop();
        if (x <= 0 || x > n)continue;
        ans += wei.back() * add;
        wei.pop_back();
        w--;
        if (op >= 0)pq.push({ cal(n,x + 1,k) * cal(m,y,k),x + 1,y,1 });
        if (op <= 0)pq.push({ cal(n,x - 1,k) * cal(m,y,k),x - 1,y,-1 });
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