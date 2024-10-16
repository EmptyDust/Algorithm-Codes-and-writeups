#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;

void solve() {
    int n, m;std::cin >> n >> m;
    std::vector<int> adj[n + 1];
    for (int i = 0;i < m;++i) {
        int u, v;std::cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    std::vector<int> color(n + 1, -1);
    bool bob = 1;
    std::function<void(int, int, int)> dfs = [&](int u, int p, int c) {
        if (!bob)return;
        if (color[u] != -1) {
            if (color[u] != c)bob = false;
            return;
        }
        color[u] = c;
        for (int v : adj[u])if (v != p) {
            dfs(v, u, !c);
        }
        };
    dfs(1, 0, 1);
    if (bob) {
        std::cout << "Bob" << std::endl;
        std::vector<int> pa, pb;
        for (int i = 1;i <= n;++i) {
            if (color[i])pa.push_back(i);
            else pb.push_back(i);
        }

        int x, y;
        {
            int a, b;std::cin >> a >> b;
            x = a;
            if (pa.size()) {
                std::cout << pa.back() << ' ' << x << std::endl;
                pa.pop_back();
            }
            else {
                std::cout << pb.back() << ' ' << x << std::endl;
                pb.pop_back();
            }
        }

        if (n > 1) {
            int a, b;std::cin >> a >> b;
            if (x == a)
                y = b;
            else y = a;

            if (pb.size()) {
                std::cout << pb.back() << ' ' << y << std::endl;
                pb.pop_back();
            }
        }


        for (int _ = 2;_ < n;++_) {
            int a, b;std::cin >> a >> b;
            if (pa.size()) {
                if (a == x || b == x) {
                    std::cout << pa.back() << ' ' << x << std::endl;
                    pa.pop_back();
                }
                else if (pb.empty()) {
                    if (a != y)
                        std::cout << pa.back() << ' ' << a << std::endl;
                    else
                        std::cout << pa.back() << ' ' << b << std::endl;
                    pa.pop_back();
                }
                else {
                    std::cout << pb.back() << ' ' << y << std::endl;
                    pb.pop_back();
                }
            }
            else {
                if (a != x)
                    std::cout << pb.back() << ' ' << a << std::endl;
                else
                    std::cout << pb.back() << ' ' << b << std::endl;
                pb.pop_back();
            }
        }
    }
    else {
        std::cout << "Alice" << std::endl;
        for (int _ = 0;_ < n;++_) {
            std::cout << "1 2" << std::endl;
            int x, y;std::cin >> x >> y;
        }
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t;std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}