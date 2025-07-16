#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using u128 = unsigned __int128;

using a2 = std::array<int, 2>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 2e9;
// const int mod = 1e9 + 7;
const int mod = 998244353;

void solve() {
    int n, L, x, y, k;
    std::cin >> n >> L >> x >> y >> k;
    std::vector<a2> ones;
    std::vector<int> pos;
    int cur = 0;
    for (int s = 31;s >= 0;--s)if (y >> s & 1) {
        int u = (cur ^ x) & (-1 ^ ((1 << s) - 1));
        ones.push_back({ u, u + (1 << s) });
        pos.push_back(u);
        pos.push_back(u + (1 << s));
        pos.push_back(u - L + 1);
        pos.push_back(u + (1 << s) - L + 1);
        cur |= 1 << s;
    }
    {
        int u = y ^ x;
        ones.push_back({ u,u + 1 });
        pos.push_back(u);
        pos.push_back(u + 1);
        pos.push_back(u - L + 1);
        pos.push_back(u + 1 - L + 1);
    }
    ranges::sort(ones);
    ranges::sort(pos);
    pos.erase(std::unique(pos.begin(), pos.end()), pos.end());
    auto cal = [&](int x) {
        int l = x, r = x + L;
        int res = 0;
        for (auto [s, e] : ones) {
            s = std::max(l, s);
            e = std::min(e, r);
            if (e > s)res += e - s;
        }
        return res;
        };
    pos.push_back(inf);
    for (int i = 1;i < pos.size();++i) {
        int a = cal(pos[i - 1]);
        int b = cal(pos[i] - 1);
        if (a == b) {
            if (a != k) continue;
            int u = std::max(pos[i - 1], 0);
            int v = std::min(pos[i] - 1, n - L + 1);
            if (u <= v) {
                std::cout << u;
                return;
            }
        }
        else if (a <= k && k <= b) {
            int ans = pos[i - 1] + k - a;
            if (0 <= ans && ans + L - 1 <= n) {
                std::cout << ans;
                return;
            }
        }
        else if (b <= k && k <= a) {
            int ans = pos[i - 1] + a - k;
            if (0 <= ans && ans + L - 1 <= n) {
                std::cout << ans;
                return;
            }
        }
    }
    std::cout << -1;
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