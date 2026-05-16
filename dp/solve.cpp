#include <bits/stdc++.h>

using a2 = std::array<int, 2>;

struct dsu {
    std::vector<int> fa;
    dsu(int n) {
        fa.resize(n);
        std::iota(fa.begin(), fa.end(), 0);
    }
    int get_root(int x) {
        return fa[x] = (x == fa[x] ? x : get_root(fa[x]));
    }
    bool merge(int u, int v) {
        if (get_root(u) != get_root(v)) {
            fa[get_root(u)] = get_root(v);
            return true;
        }
        return false;
    }
};

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n);
    for (auto &x : a)
        std::cin >> x;
    dsu d(n + 1);
    while (m--) {
        int c = 0;
        int p;
        std::cin >> p;
        p--;
        while (p < n) {
            c += d.get_root(p) - p;
            p = d.get_root(p);
            if (p >= n)
                break;
            c++;
            int np = p + a[p];
            if (a[p] > 1)
                a[p]--;
            if (a[p] == 1)
                d.merge(p, p + 1);
            p = np;
            // std::cout << p << ' ';
        }
        std::cout << c << '\n';
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}