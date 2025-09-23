#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using a2 = std::array<int, 2>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
// const int mod = 1e9 + 7;
const int mod = 998244353;

void solve() {
    int n, k;std::cin >> n >> k;
    std::vector<int> t(n);
    std::multiset<int> out;
    for (auto& x : t) {
        std::cin >> x;
        x %= k;
        out.insert(x);
    }
    if (n == 1) {
        std::cout << 0;
        return;
    }
    std::priority_queue<a2, std::vector<a2>, std::greater<a2>> pq;
    auto find_next = [&](int x) {
        int y = k - x;
        auto it = out.lower_bound(y);
        int ny = it != out.end() ? (*it) : (*out.begin());
        pq.push({ (x + ny) % k, ny });
        };
    int a = *out.begin();
    out.extract(a);
    find_next(a);
    i64 ans = 0;
    while (pq.size()) {
        auto [cost, y] = pq.top();
        pq.pop();
        if (!out.contains(y)) continue;
        ans += cost;
        out.extract(y);
        if (out.empty()) break;
        int x = (cost - y + k) % k;
        find_next(x);
        find_next(y);
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