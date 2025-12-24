#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using u128 = unsigned __int128;

using a2 = std::array<i64, 2>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
// const int mod = 1e9 + 7;
const int mod = 998244353;

void solve() {
    int n;std::cin >> n;
    std::vector<i64> a(n), p(n);
    for (auto& x : a) std::cin >> x, x *= 2;
    // for (int i = 1;i < n;++i) {
    //     p[i] = p[i - 1] + (a[i] - a[i - 1]) * (i % 2 ? 1 : -1);
    // }
    // std::deque<a2> dq;
    std::vector<a2> pos(1, { a[0], 0 });
    for (int i = 1;i < n;++i) {
        i64 r = 0;
        while (pos.size() && pos.back()[0] >= a[i]) {
            r = pos.back()[1] + 1;
            pos.pop_back();
        }
        std::vector<a2> np;
        for (int j = (int)pos.size() - 1;j >= 0;--j) {
            if (j == (int)pos.size() - 1) np.push_back({ a[i] * 2 - pos[j][0] - 1, r });
            else np.push_back({ a[i] * 2 - pos[j][0], pos[j + 1][1] + 1 });
        }
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