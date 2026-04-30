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
    i64 n, k;std::cin >> n >> k;
    auto cal = [&](auto&& self, i64 l, i64 r) ->pii {
        if (r - l + 1 < k)return { 0,0 };
        i64 ret = 0, cnt = 0;
        if ((r - l + 1) % 2) {
            auto res = self(self, l, (r + l) / 2 - 1);
            ret = res.first;
            cnt = res.second;
            ret += cnt * (r + 1) - ret;
            // if (r - l + 1 == 7)std::cout << ret << '\n';
            cnt *= 2;
            ret += (r + l) / 2;
            cnt++;
        }
        else {
            auto res = self(self, l, (r + l) / 2);
            ret = res.first;
            cnt = res.second;
            ret += cnt * (r + 1) - ret;
            cnt *= 2;
        }
        return { ret,cnt };
        };
    std::cout << cal(cal, 1, n).first;
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