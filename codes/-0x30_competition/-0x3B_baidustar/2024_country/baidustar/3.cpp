#include <bits/stdc++.h>

using i64 = long long;
using a3 = std::array<int, 3>;

const int inf = 1e9 + 7;

/*
0100
1010
1010
0100
*/

/*
001
0111
11011
0111
001

*/

const int MAXN = 1010;

int map[MAXN][MAXN];

int dp[MAXN][MAXN];

void solve() {
    for (int i = 1;i <= 1000;++i)
        for (int j = 1;j <= 1000;++j)
            dp[i][j] = inf;
    int n, x1, y1, x2, y2;
    std::cin >> n >> x1 >> y1 >> x2 >> y2;
    for (int i = 0;i < n;++i) {
        int x, y;std::cin >> x >> y;
        map[x][y] = 1;
    }
    std::priority_queue<a3, std::vector<a3>, std::greater<a3>> pq;
    pq.push({ 0,x1,y1 });
    bool bianjie = 0;
    auto check = [&](int x, int y) {
        return 0 < x && x <= 1000 && 0 < y && y <= 1000;
        };
    auto put = [&](int x) {
        if (bianjie)return;
        bianjie = true;
        // std::cout << x << " ";
        for (int i = 1;i <= 1000;++i) {
            pq.push({ x,i,1 });
            pq.push({ x,i,1000 });
            pq.push({ x,1,i });
            pq.push({ x,1000,i });
        }
        };
    int dirx[4] = { 1,-1,0,0 };
    int diry[4] = { 0,0,1,-1 };
    while (pq.size()) {
        auto [dis, x, y] = pq.top();
        // std::cout << dis << ' ' << x << ' ' << y << '\n';
        pq.pop();
        if (x == x2 && y == y2) {
            std::cout << dis;
            // std::cout << ' ' << dp[5][1] << '\n';
            return;
        }
        dis += map[x][y];
        if (!check(x, y)) {
            put(dis);
            continue;
        }
        if (dp[x][y] <= dis)continue;
        dp[x][y] = dis;
        // std::cout << dis << '\n';
        for (int i = 0;i < 4;++i) {
            int nx = x + dirx[i], ny = y + diry[i];
            pq.push({ dis,nx,ny });
        }
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}