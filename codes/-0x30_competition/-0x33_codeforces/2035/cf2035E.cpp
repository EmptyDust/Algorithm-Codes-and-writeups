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
const i64 inf = 8e18;
// const int mod = 1e9 + 7;
const int mod = 998244353;

int next(i64 now, i64 z, i64 k){
    if (now <= 0 || now >= z)return -1;
    i64 ntime = (z - 1) / now;
    i64 t = z / ntime + (z % ntime != 0);
    return std::min(std::max(now + 1, t), (now / k + 1) * k + 1);
}

void solve() {
    i64 x, y, z, k;std::cin >> x >> y >> z >> k;
    i64 cur = 1;
    i64 ans = inf;
    while (1)
    {
        if (cur <= 0 || cur > z)break;
        i64 cnt = (cur - 1) / k;
        i64 res = cnt * y + cur * x;
        i64 sy = z - (k + cnt * k) * cnt / 2;
        if (sy < 0){
            ans = std::min(ans, res);
            break;
        }
        if (sy)res += ((sy - 1) / cur + 1) * y;

        ans = std::min(ans, res);

        cur = next(cur, sy, k);
        // std::cout << cur << ' ';
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