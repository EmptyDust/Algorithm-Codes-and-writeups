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

int cal(int x) {
    auto l = 0, r = 1000;
    while (l < r) {
        auto mid = l + r >> 1;
        if ((1 + mid) * mid / 2 >= x)r = mid;
        else l = mid + 1;
    }
    return l;
}

void solve() {
    int n;std::cin >> n;
    std::vector<int> a(n);
    for (int& x : a)std::cin >> x;
    for (int i = 0;i < n;++i)a.push_back(a[i]);
    std::vector dp(32, std::vector<int>(2 * n, -1));
    for (int j = 0;j < 32;++j) {
        for (int i = 2 * n - 1;i >= 0;--i) {
            if (i < 2 * n - 1) dp[j][i] = dp[j][i + 1];
            if (a[i] >> j & 1) dp[j][i] = i;
        }
    }
    std::vector<int> res(n);
    int max = 0;
    for (int i = 0;i < n;++i) {
        for (int j = 0;j < 32;++j) {
            res[i] = std::max(res[i], dp[j][i] - i);
        }
        max = std::max(cal(res[i]), max);
    }
    std::cout << max;
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