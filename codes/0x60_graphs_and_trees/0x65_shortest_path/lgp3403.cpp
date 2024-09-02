#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10;
constexpr i64 inf = 1e18;
int nums[MAXN], n;
using pt = std::pair<int, int>;

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    i64 h;std::cin >> h;
    i64 x, y, z;std::cin >> x >> y >> z;
    std::vector<i64> f(x, -1);
    std::priority_queue<i64, std::vector<i64>, std::greater<i64>> q;
    q.push(1);
    while (q.size()) {
        i64 num = q.top();
        q.pop();
        if (~f[num % x])continue;
        f[num % x] = num;
        if (num + y <= h)q.push(num + y);
        if (num + z <= h)q.push(num + z);
    }
    i64 ans = 0;
    for (int i = 0;i < x;++i) {
        if (~f[i])
            ans += (h - f[i]) / x + 1;
    }
    std::cout << ans;
    return 0;
}