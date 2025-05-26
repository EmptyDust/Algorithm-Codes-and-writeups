#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<int, int>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

// const int dx[8] = { -1, 0, 1, 0, -1, -1, 1, 1 }, dy[8] = { 0, 1, 0, -1, -1, 1, -1, 1 };
const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
const i64 INF = 9114511145141919810;
const int mod = 1e9 + 7;

int dx[2] = { 0,-1 };
int dy[2] = { -1,0 };
void solve()
{
    int n, m;   std::cin >> n >> m;
    std::vector<std::vector<char>> a(n + 1, std::vector<char>(m + 1, 0));
    for (int i = 1;i <= n;i++) {
        for (int j = 1; j <= m;j++)
            std::cin >> a[i][j];
    }

    for (int i = 1; i <= n;i++)
        for (int j = 1;j <= m;j++)
            for (int t = 0;t < 2;t++)
                if (a[i][j] == a[i + dx[t]][j + dy[t]] && a[i][j] == 'B') {
                    std::cout << "No";
                    return;
                }

    int nox = 0, noy = 0;
    if (!(n & 1)) nox = n / 2;
    if (!(m & 1)) noy = m / 2;

    if (nox)
        for (int i = 1;i <= m;i++)
            if (a[nox][i] == 'B' || a[nox + 1][i] == 'B') {
                std::cout << "No";
                return;
            }
    if (noy)
        for (int i = 1;i <= n;i++)
            if (a[i][noy] == 'B' || a[i][noy + 1] == 'B') {
                std::cout << "No";
                return;
            }
    std::cout << "Yes";
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    solve();
}