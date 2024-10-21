#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<i64, i64>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
// const int mod = 1e9 + 7;
const int mod = 998244353;

void solve() {
    int n;std::cin >> n;
    std::vector<i64> a(n), info(n, -1);
    for (auto& x : a)std::cin >> x;
    std::vector<int> b(n);
    for (auto& x : b)std::cin >> x, x--;
    std::priority_queue<pii, std::vector<pii>, std::greater<pii>> pq;
    pq.push({ 0,0 });
    while (pq.size()){
        auto [dis, p] = pq.top();
        pq.pop();
        if (info[p] != -1 && info[p] <= dis)continue;
        // std::cout << p << ' ' << dis << '\n';
        info[p] = dis;
        if (p)pq.push({ dis,p - 1 });
        pq.push({ dis + a[p],b[p] });
    }
    std::vector<i64> pre(a);
    for (int i = 1;i < n;++i)pre[i] += pre[i - 1];
    i64 ans = 0;
    for (int i = 0;i < n;++i)if (info[i] != -1)
        ans = std::max(ans, pre[i] - info[i]);
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