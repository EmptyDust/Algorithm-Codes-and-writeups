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
    int n, d, k;std::cin >> n >> d >> k;
    std::vector<int> c(n + 2);
    for (int i = 0;i < k;++i) {
        int l, r;std::cin >> l >> r;
        c[std::max(0, l - d + 1)]++;
        c[r + 1]--;
    }
    for (int i = 1;i <= n;++i)c[i] += c[i - 1];
    int L = 1, R = n - d + 2;
    int min = *std::min_element(c.begin() + L, c.begin() + R);
    int max = *std::max_element(c.begin() + L, c.begin() + R);
    int mnp = -1, mxp = -1;
    for (int i = 1;i <= n;++i) {
        if (c[i] == min && mnp == -1)mnp = i;
        if (c[i] == max && mxp == -1)mxp = i;
    }
    std::cout << mxp << ' ' << mnp;
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