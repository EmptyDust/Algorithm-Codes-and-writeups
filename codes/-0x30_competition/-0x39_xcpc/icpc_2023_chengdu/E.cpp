#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<int, int>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int dx[8] = { -1, 0, 1, 0, -1, -1, 1, 1 }, dy[8] = { 0, 1, 0, -1, -1, 1, -1, 1 };
const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
const i64 INF = 1e18;
const int mod = 1e9 + 7;

void solve()
{
    int n, m;   std::cin >> n >> m;
    std::map<int, std::vector<pii>> a;
    std::vector map(n, std::vector<int>(m));
    for (int i = 1;i <= n;i++)
        for (int j = 1;j <= m;j++) {
            std::cin >> map[i][j];
            int x;  std::cin >> x;
            a[x].push_back({ i,j });
        }
    

    i64 ans = 0;
    for (auto [x, v] : a) {
        int sz = v.size();
        for (int i = 0;i < sz;i++)
            for (int j = 0;j < sz;j++)
                ans += std::abs(v[i].first - v[j].first) + std::abs(v[i].second - v[j].second);
    }
    std::cout << ans;
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int t = 1;
    // std::cin >> t;
    while (t--) {
        solve();
        std::cout << '\n';
    }
}