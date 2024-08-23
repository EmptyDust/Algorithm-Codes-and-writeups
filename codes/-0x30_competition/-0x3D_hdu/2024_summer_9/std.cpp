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
    i64 k, x, y;std::cin >> k >> x >> y;
    std::priority_queue<pii, std::vector<pii>, std::greater<pii>> q;q.push({ 0,0 });
    bool a = false, b = false;
    while (q.size() && q.top().first <= k + std::max(x, y)) {
        if (a && b)break;
        auto [num, p] = q.top();
        q.pop();
        if (num >= k) {
            if (p)a = true;
            else b = true;
        }
        if (num >= k)continue;
        q.push({ num + x,!p });
        q.push({ num + y,!p });
    }
    std::cout << (a ? "YES" : "NO") << '\n';
    std::cout << (b ? "YES" : "NO") << '\n';
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t;std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}