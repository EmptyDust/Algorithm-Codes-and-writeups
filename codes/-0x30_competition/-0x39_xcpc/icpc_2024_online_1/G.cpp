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
    int n;std::cin >> n;
    std::vector<int> oa(n);
    for (int& x : oa)std::cin >> x;
    auto l = 0, r = (int)1e9 + 1;
    auto getmid = [&](int c0, int c1) {
        return c1 >= (c0 + c1 + 1) / 2;
        };
    auto check = [&](int x)->bool {
        std::vector<int> a(n + 1);
        for (int i = 1;i <= n;++i)a[i] = oa[i - 1] <= x;
        std::vector<std::vector<int>> b(n + 1, std::vector<int>(n + 1));
        for (int i = 1;i <= n;++i) {
            int cnt0 = 0, cnt1 = 0;
            for (int j = i;j <= n;++j) {
                if (a[j])cnt1++;
                else cnt0++;
                b[i][j] = getmid(cnt0, cnt1);
            }
        }
        for (int i = 1;i <= n;++i) {
            for (int j = 1;j <= n;++j) {
                b[i][j] = b[i][j] + b[i][j - 1] + b[i - 1][j] - b[i - 1][j - 1];
            }
        }
        int c0 = 0, c1 = 0;
        for (int i = 1;i <= n;++i) {
            for (int j = i;j <= n;++j) {
                int cnt1 = b[j][j] - b[i - 1][j] - b[j][i - 1] + b[i - 1][i - 1];
                int cnt0 = (1 + j - i + 1) * (j - i + 1) / 2 - cnt1;
                int mid = getmid(cnt0, cnt1);
                if (mid)c1++;
                else c0++;
            }
        }
        return getmid(c0, c1);
        };
    while (l < r) {
        auto mid = l + r >> 1;
        if (check(mid))r = mid;
        else l = mid + 1;
    }
    std::cout << l;
    // check(93);
}
    
signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t = 1;
    while (t--) {
        solve();
        std::cout << '\n';
    }
    return 0;
}