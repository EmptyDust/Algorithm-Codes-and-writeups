#include <bits/stdc++.h>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

int query(int x) {
    std::cout << "? " << x + 1 << std::endl;
    int res;
    std::cin >> res;
    return res;
}

constexpr int B = 71;

void solve() {
    int n;
    std::cin >> n;

    std::vector<std::vector<int>> adj(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        std::cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    std::vector<int> p(n, -1), h(n);
    auto dfs = [&](auto self, int x) -> void {
        for (auto y : adj[x]) {
            if (y == p[x]) {
                continue;
            }
            p[y] = x;
            self(self, y);
            h[x] = std::max(h[x], h[y] + 1);
        }
        };
    dfs(dfs, 0);

    int leaf = std::find(h.begin(), h.end(), 0) - h.begin();
    for (int i = 0; i < B; i++) {
        if (query(leaf) == 1) {
            std::cout << "! " << leaf + 1 << std::endl;
            return;
        }
    }

    auto find = [&](auto self, int x) -> int {
        std::vector<int> a;
        for (auto y : adj[x]) {
            if (y == p[x] || h[y] < B) {
                continue;
            }
            a.push_back(y);
        }
        if (a.empty()) {
            return x;
        }
        for (auto y : a) {
            if (y == a.back() || query(y) == 1) {
                return self(self, y);
            }
        }
        assert(false);
        };
    int x = find(find, 0);

    std::vector<int> a;
    for (int i = x; i != -1; i = p[i]) {
        a.push_back(i);
    }
    std::reverse(a.begin(), a.end());

    int lo = 0, hi = a.size() - 1;
    while (lo < hi) {
        int x = (lo + hi + 1) / 2;
        if (query(a[x]) == 1) {
            lo = x;
        }
        else {
            hi = x - 1;
            lo = std::max(0, lo - 1);
            hi = std::max(0, hi - 1);
        }
    }

    std::cout << "! " << a[lo] + 1 << std::endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
