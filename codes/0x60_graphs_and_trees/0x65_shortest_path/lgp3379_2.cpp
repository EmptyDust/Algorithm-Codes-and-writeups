#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

int main() {
    int n, m, R;
    std::cin >> n >> m >> R;

    std::vector<std::vector<int>> adj(n + 1);
    for (int i = 1, u, v; i < n; i++) {
        std::cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    std::vector<int> dfn(n + 1);
    std::vector<int> depth(n + 1, 0);
    std::vector<int> parent(n + 1, 0);
    std::vector<std::vector<int>> mi;
    int dn = 0;  // Move dn inside main.

    // DFS Lambda (C++23 implicit lambda capture)
    auto dfs = [&](this auto&& self, int id, int f) -> void {
        dfn[id] = ++dn;
        parent[id] = f;
        depth[id] = depth[f] + 1;

        for (int it : adj[id]) {
            if (it != f) {
                self(it, id); // Correct recursive call: self(self, it, id);
            }
        }
        };

    dfs(R, 0); // Initiate the DFS

    mi.resize(static_cast<size_t>(std::ceil(std::log2(n)) + 1), std::vector<int>(n + 1));
    for (int i = 1; i <= n; i++) {
        mi[0][i] = parent[i];
    }

    for (int i = 1; i <= static_cast<int>(std::floor(std::log2(n))); i++) {
        for (int j = 1; j + (1 << i) - 1 <= n; j++) {
            mi[i][j] = depth[mi[i - 1][j]] < depth[mi[i - 1][j + (1 << i - 1)]]
                ? mi[i - 1][j]
                : mi[i - 1][j + (1 << i - 1)];
        }
    }

    depth[0] = -1;  // Crucial depth correction

    // LCA Lambda
    auto lca = [&](int u, int v) {
        if (u == v) return u;
        int u_dfn = dfn[u];
        int v_dfn = dfn[v];

        if (u_dfn > v_dfn) std::swap(u_dfn, v_dfn);

        int d = static_cast<int>(std::floor(std::log2(v_dfn - u_dfn + 1)));

        return depth[mi[d][u_dfn]] < depth[mi[d][v_dfn - (1 << d) + 1]]
            ? mi[d][u_dfn]
            : mi[d][v_dfn - (1 << d) + 1];
        };

    for (int i = 1, u, v; i <= m; i++) {
        std::cin >> u >> v;
        std::cout << lca(u, v) << std::endl;
    }

    return 0;
}