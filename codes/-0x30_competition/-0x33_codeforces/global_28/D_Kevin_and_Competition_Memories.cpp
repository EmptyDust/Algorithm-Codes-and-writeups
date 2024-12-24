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
    int n, m;std::cin >> n >> m;
    int kevin;std::cin >> kevin;
    std::vector<int> a, b(m);a.push_back(kevin);
    for (int i = 0;i < n - 1;++i) {
        int x;std::cin >> x;
        if (x > kevin)a.push_back(x);
    }
    int cnt = 0;
    for (int& x : b) {
        std::cin >> x;
        if (kevin >= x) cnt++;
    }
    ranges::sort(a);ranges::sort(b);
    n = a.size();
    std::vector<int> number(n);
    for (int i = 0, j = 0;i < n;++i) {
        while (j < m && b[j] <= a[i])j++;
        number[i] = j;
    }

    std::vector<i64> ans(m + 2);
    for (int i = 1;i <= m;++i) {
        // int mul = std::min(m / i, (cnt - 1) / i + 1);
        ans[i] = 1ll * m / i * n;
    }

    std::vector<i64> ans2(m + 2);
    int sq = std::sqrt(m);
    for (int i = 1;i < n;++i) {
        int num = m - number[i] + cnt;
        for (int j = 1;j <= sq;++j) {
            // if (j == 1)std::cout << num << '\n';
            ans[j] -= num / j;
        }
        for (int j = 1;j <= sq;++j) {
            int up = num / j;
            int down = num / (j + 1) + 1;
            // std::cout << j << ' ' << down << ' ' << up << '\n';
            ans2[down] += j, ans2[up + 1] -= j;
        }
    }
    for (int i = 1;i <= m;++i) {
        ans2[i] += ans2[i - 1];
        if (i > sq)ans[i] -= ans2[i];
    }
    for (int i = 1;i <= m;++i)
        std::cout << ans[i] << ' ';
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