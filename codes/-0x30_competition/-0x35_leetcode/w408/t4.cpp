#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;


class Solution {
    struct Circle
    {
        i64 a = 0, b = 0, r = 0;
        Circle(i64 a, i64 b, i64 r) :a(a), b(b), r(r) {}
        bool jiao(Circle x) {
            return (a - x.a) * (a - x.a) + (b - x.b) * (b - x.b) <= (x.r + r) * (x.r + r);
        }
        bool px(int x) {
            int nx = std::abs(x - a);
            return nx <= r;
        }
        bool py(int y) {
            int ny = std::abs(y - b);
            return ny <= r;
        }
    };
public:
    bool canReachCorner(int X, int Y, std::vector<std::vector<int>>& circles) {
        int n = circles.size();
        std::vector<Circle> c;
        for (auto vt : circles)
            c.push_back(Circle(vt[0], vt[1], vt[2]));
        std::vector<std::vector<int>> adj(n + 2, std::vector<int>(n + 2));
        for (int i = 0;i < n;++i)for (int j = 0;j < n;++i)
            if (c[i].jiao(c[j]))
                adj[i][j] = 1;
        for (int i = 0;i < n;++i) {
            if (c[i].px(0) || c[i].py(Y))adj[i][n] = adj[n][i] = true;
            if (c[i].px(X) || c[i].py(0))adj[i][n + 1] = adj[n + 1][i] = true;
        }
        std::vector<int> vis(n + 2);
        std::queue<int> q;q.push(n + 1);
        while (q.size()) {
            int t = q.front();
            q.pop();
            if (vis[t])continue;
            vis[t] = 1;
            for (int i = 0;i < n + 2;++i)if (adj[t][i])q.push(i);
        }
        return !vis[n];
    }
};