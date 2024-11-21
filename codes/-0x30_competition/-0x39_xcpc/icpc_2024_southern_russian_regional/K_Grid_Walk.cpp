#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<int, int>;
using a3 = std::array<i64, 3>;
using a4 = std::array<int, 4>;

const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
// const int mod = 1e9 + 7;
const int mod = 998244353;

void solve() {
    i64 n, a, b;std::cin >> n >> a >> b;
    i64 X = n, Y = n;
    while (std::gcd(X, a) != 1)X--;
    while (std::gcd(Y, b) != 1)Y--;
    i64 sum = 0;
    for (int i = 1;i <= X;++i) {
        sum += std::gcd(i, a) + 1;
    }
    for (int i = 2;i <= Y;++i) {
        sum += 1 + std::gcd(i, b);
    }
    std::vector dis(n - X + 1, std::vector<i64>(n - Y + 1, -1));
    std::vector cost(n - X + 1, std::vector<i64>(n - Y + 1, -1));
    for (int i = 0;i <= n - X;++i) {
        for (int j = 0;j <= n - Y;++j) {
            int cX = i + X;
            int cY = j + Y;
            cost[i][j] = std::gcd(cX, a) + std::gcd(cY, b);
        }
    }
    auto vaild = [&](int t, int s) {
        return X <= t && t <= n && Y <= s && s <= n;
        };
    std::priority_queue<a3, std::vector<a3>, std::greater<a3>> pq;
    dis[0][0] = sum;
    pq.push({ sum,0,0 });
    pii add[4] = { {1,0},{0,1},{0,-1},{-1,0} };
    while (pq.size()) {
        auto [sum, x, y] = pq.top();
        if (dis[x][y] != sum) continue;
        pq.pop();
        dis[x][y] = sum;
        for (int i = 0;i < 4;++i) {
            int nx = x + add[i].first, ny = y + add[i].second;
            if (!vaild(nx + X, ny + Y))continue;
            i64 nsum = sum + cost[nx][ny];
            if (dis[nx][ny] == -1 || nsum < dis[nx][ny]) {
                dis[nx][ny] = nsum;
                pq.push({ nsum,nx,ny });
            }
        }
    }
    std::cout << dis.back().back();
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t = 1;
    while (t--) {
        solve();
        // std::cout << "end";
    }
    return 0;
}