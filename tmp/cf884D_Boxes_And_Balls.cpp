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
    int n;std::cin >> n;
    std::priority_queue<i64, std::vector<i64>, std::greater<i64>> c;
    for (int i = 0;i < n;++i) {
        i64 x;
        std::cin >> x;
        c.push(x);
    }
    i64 ans = 0;
    if (c.size() % 2 == 0) {
        i64 x = c.top();c.pop();
        i64 y = c.top();c.pop();
        ans += x + y;
        c.push(x + y);
    }
    while (c.size() > 1) {
        i64 x = c.top();c.pop();
        i64 y = c.top();c.pop();
        i64 z = c.top();c.pop();
        i64 sum = x + y + z;
        ans += sum;
        c.push(sum);
    }
    std::cout << ans;
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