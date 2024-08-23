#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<int, int>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;
using a5 = std::array<int, 5>;

const int N = 1e6;
const int MAXN = 2e3 + 10;
const int inf = 1e9;
// const int mod = 1e9 + 7;
const int mod = 998244353;
int map[MAXN][MAXN], vis[MAXN][MAXN];

void solve() {
    int n, m;std::cin >> n >> m;
    int r, c;std::cin >> r >> c;
    int x, y;std::cin >> x >> y;
    for (int i = 1;i <= n;++i) {
        std::string s;std::cin >> s;
        for (int j = 1;j <= m;++j) {
            map[i][j] = s[j - 1] == '*';
        }
    }
    std::priority_queue<a5, std::vector<a5>, std::greater<a5>> q;
    q.push({ 0,r,c,x,y });
    auto check = [&](int x, int y) {
        return 1 <= x && x <= n && 1 <= y && y <= m;
        };
    int dirx[4] = { 1,-1,0,0 };
    int diry[4] = { 0,0,1,-1 };
    while (q.size()) {
        auto [d, a, b, x, y] = q.top();
        q.pop();
        if (vis[a][b] || map[a][b] || x < 0 || y < 0)continue;
        vis[a][b] = true;
        for (int i = 0;i < 4;++i) {
            int nd = d + (i == 3 || i == 2);
            int na = a + dirx[i];
            int nb = b + diry[i];
            int nx = x - (i == 3);
            int ny = y - (i == 2);
            if (check(na, nb))
                q.push({ nd,na,nb,nx,ny });
        }
    }
    int cnt = 0;
    for (int i = 1;i <= n;++i) {
        for (int j = 1;j <= m;++j) {
            cnt += vis[i][j];
        }
    }
    std::cout << cnt;
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