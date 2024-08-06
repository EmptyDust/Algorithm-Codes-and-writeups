#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;
using a3 = std::array<int, 3>;

struct dsu {
    std::vector<int> d;
    dsu(int n) { d.resize(n); iota(d.begin(), d.end(), 0); }
    int get_root(int x) { return d[x] = (x == d[x] ? x : get_root(d[x])); };
    bool merge(int u, int v) {
        if (get_root(u) != get_root(v)) {
            d[get_root(u)] = get_root(v);
            return true;
        }
        else return false;
    }
    bool check() {
        int x = d[0];
        for (int i = 0;i < d.size();++i)if (d[i] != x) {
            return false;
        }
        return true;
    }
};

int map[1000][1000], vis[1000][1000], distance[50][50];
signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    memset(distance, -1, sizeof distance);
    int n, m;std::cin >> n >> m;
    int idx = 0;
    for (int i = 0;i < n;++i) {
        std::string s;std::cin >> s;
        for (int j = 0;j < m;++j) {
            switch (s[j])
            {
            case '.':
                map[i][j] = -1;
                break;
            case '#':
                map[i][j] = -2;
                break;
            case '*':
                map[i][j] = idx++;
                break;
            }
        }
    }
    auto vaild = [&](int x, int y) {return 0 <= x && x < n && 0 <= y && y < m;};
    int dir_x[4] = { 0,0,1,-1 };
    int dir_y[4] = { 1,-1,0,0 };
    auto bfs = [&](int x, int y) {
        for (int i = 0;i < n;++i)for (int j = 0;j < m;++j)vis[i][j] = 0;
        int id = map[x][y];
        std::queue<a3> q;
        q.push({ x,y,0 });

        while (q.size()) {
            auto [x, y, dis] = q.front();
            q.pop();
            if (vis[x][y] || map[x][y] == -2)continue;
            vis[x][y] = true;
            if (map[x][y] >= 0 && map[x][y] != id) {
                distance[id][map[x][y]] = dis;
            }
            for (int i = 0;i < 4;++i) {
                int nx = x + dir_x[i], ny = y + dir_y[i];
                if (vaild(nx, ny)) {
                    q.push({ nx,ny,dis + 1 });
                }
            }
        }
        };
    for (int i = 0;i < n;++i)for (int j = 0;j < m;++j) {
        if (map[i][j] >= 0)bfs(i, j);
    }
    std::priority_queue<a3, std::vector<a3>, std::greater<a3>> pq;
    for (int i = 0;i < idx;++i)for (int j = 0;j < idx;++j) {
        if (i != j) {
            if (distance[i][j] == -1) {
                std::cout << "No";
                return 0;
            }
            pq.push({ distance[i][j],i,j });
        }
    }
    dsu d(idx);
    i64 ans = 0;
    while (pq.size()) {
        auto [dis, u, v] = pq.top();
        pq.pop();
        if (d.merge(u, v))ans += dis;
    }
    std::cout << ans;
    return 0;
}