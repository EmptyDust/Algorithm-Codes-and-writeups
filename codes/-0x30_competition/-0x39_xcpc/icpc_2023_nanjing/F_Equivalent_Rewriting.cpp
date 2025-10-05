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
    std::vector adj(m + 1, std::vector<int>());

    std::vector a(n + 1, std::vector<int>());
    for (int i = 1;i <= n;i++) {
        int cnt;    std::cin >> cnt;
        for (int j = 1;j <= cnt;j++)
        {
            int x;  std::cin >> x;
            a[i].push_back(x);
            adj[x].push_back(i);
        }
    }

    std::vector<int> ans(n + 1);
    std::iota(ans.begin(), ans.end(), 0);
    for (int i = 1;i <= n - 1;i++) {
        int f = 1;
        for (auto x : a[i]) {
            if (adj[x].back() == i + 1) {
                f = 0;
                break;
            }
        }
        if (f) {
            std::swap(ans[i], ans[i + 1]);
            break;
        }
    }

    int f = 1;
    for (int i = 1;i <= n;i++) if (ans[i] != i) f = 0;

    if (f) std::cout << "No";
    else {
        std::cout << "Yes\n";
        for (int i = 1;i <= n;i++)
            std::cout << ans[i] << " ";
    }
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int t = 1;
    std::cin >> t;
    while (t--) {
        solve();
        std::cout << '\n';
    }
}