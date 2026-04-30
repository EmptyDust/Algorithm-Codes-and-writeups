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
    int n, m, q;std::cin >> n >> m >> q;
    std::vector<pii> info;
    info.push_back({ m,m });
    for (int i = 0;i < q;++i) {
        int x;std::cin >> x;
        std::vector<pii> tmp, ni;
        for (auto [l, r] : info) {
            if (l <= x && x <= r) {
                tmp.push_back({ 1,1 });
                tmp.push_back({ n,n });
            }
            if (l == x) {
                l++;
            }
            if (r == x) {
                r--;
            }
            if (l > r)continue;
            if (l > x)l--;
            if (r < x)r++;
            tmp.push_back({ l,r });
            // if (x == 1)std::cout << l << ' ' << r << '\n';
        }

        ranges::sort(tmp);
        int pr = -1;
        for (auto& [l, r] : tmp) {
            // if (x == 1)std::cout << l << ' ' << r << '\n';
            l = std::max(1, l);
            r = std::min(n, r);
            if (l > r)continue;
            if (l <= pr) {
                pr = ni.back().second = std::max(ni.back().second, r);
                continue;
            }
            ni.push_back({ l,r });
            pr = r;
        }
        int ans = 0;
        info = ni;
        for (auto [l, r] : info) {
            // if (x == 1)std::cout << l << ' ' << r << '\n';
            ans += r - l + 1;
        }
        std::cout << ans << ' ';
    }
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