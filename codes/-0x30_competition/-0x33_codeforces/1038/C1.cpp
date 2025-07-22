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
const int inf = 1e9;
// const int mod = 1e9 + 7;
const int mod = 998244353;

void solve() {
    int n;std::cin >> n;
    std::vector<a3> info(n);
    for (auto& [x, y, _] : info)std::cin >> x >> y;
    for (int i = 0;i < n;++i) info[i][2] = i + 1;
    ranges::sort(info);
    std::sort(info.begin(), info.begin() + n / 2, [&](a3 a, a3 b) {
        return a[1] < b[1];
        });
    std::sort(info.begin() + n / 2, info.end(), [&](a3 a, a3 b) {
        return a[1] > b[1];
        });

    for (int i = 0;i < n / 2;++i) {
        std::cout << info[i][2] << ' ' << info[n / 2 + i][2] << '\n';
    }
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