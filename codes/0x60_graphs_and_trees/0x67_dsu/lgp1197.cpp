#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 2e5 + 10;
using pt = std::pair<int, int>;
std::vector<int> adj[MAXN];

struct dsu {
    std::vector<int> d;
    int cnt = 0;//树的数量
    dsu(int n) { d.assign(n, 0); std::iota(d.begin(), d.end(), 0);cnt = n; }
    int get_root(int x) { return d[x] = (x == d[x] ? x : get_root(d[x])); }
    int count() { return cnt; }
    bool merge(int u, int v) {
        if (get_root(u) != get_root(v)) {
            cnt--;
            d[get_root(u)] = get_root(v);
            return true;
        }
        else return false;
    }
};

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int n, m;
    std::cin >> n >> m;
    int x, y;
    for (int i = 0;i < m;++i) {
        std::cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int k;
    std::cin >> k;
    std::vector<int> att(k);
    std::vector<bool> alive(n, 1);
    for (int i = 0;i < k;++i) {
        std::cin >> att[i];
        alive[att[i]] = 0;
    }
    dsu d(n);
    for (int i = 0;i < n;++i)if (alive[i]) {
        for (int nxt : adj[i])if (alive[nxt]) {
            d.merge(i, nxt);
        }
    }
    std::vector<int> ans{ d.count() - k };
    for (int i = k - 1;~i;--i) {
        int cur = att[i];
        alive[cur] = 1;
        for (int nxt : adj[cur])if (alive[nxt]) {
            d.merge(nxt, cur);
        }
        ans.push_back(d.count() - i);
    }
    std::reverse(ans.begin(), ans.end());
    for (int num : ans)std::cout << num << '\n';
    return 0;
}