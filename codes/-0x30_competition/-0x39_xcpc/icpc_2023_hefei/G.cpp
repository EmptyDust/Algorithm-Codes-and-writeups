#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<int, int>;
using a3 = std::array<int, 3>;
using a2 = std::array<int, 2>;
using a4 = std::array<int, 4>;

const int dx[8] = { -1, 0, 1, 0, -1, -1, 1, 1 }, dy[8] = { 0, 1, 0, -1, -1, 1, -1, 1 };
const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
const i64 INF = 1e18;
const int mod = 1e9 + 7;

void solve()
{
    int n, m, k;    std::cin >> n >> m >> k;
    std::string s;  std::cin >> s;
    s = " " + s;
    std::vector<int> pre(n + 1);
    for (int i = 1;i <= n;i++)
        pre[i] = pre[i - 1] + (s[i] == '0');

    int l = 1, r = n / k;
    int ans = -1;
    while (l <= r) {
        auto check = [&](int x) {
            std::vector f(n + 1, std::vector<a2>(k + 1, { inf,inf }));

            f[0][0][0] = 0;
            for (int i = 1;i <= n;i++)
                if (s[i] == '0') f[i][0][0] = 0;

            for (int i = 1;i <= n;i++)
                for (int j = 1;j <= k;j++) {
                    if (s[i] == '0') f[i][j][0] = std::min(f[i - 1][j][0], f[i - 1][j][1]);
                    else f[i][j][0] = f[i - 1][j][0];

                    f[i][j][1] = f[i - 1][j][1];
                    if (i >= x) f[i][j][1] = std::min(f[i][j][1], f[i - x][j - 1][0] + pre[i] - pre[i - x]);
                }

            return std::min(f[n][k][1], f[n][k][0]) <= m;
            };

        int mid = l + r >> 1;
        if (check(mid)) ans = mid, l = mid + 1;
        else r = mid - 1;
    }
    std::cout << ans;
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int t = 1;
    //std::cin >> t;
    while (t--) {
        solve();
        std::cout << '\n';
    }
}