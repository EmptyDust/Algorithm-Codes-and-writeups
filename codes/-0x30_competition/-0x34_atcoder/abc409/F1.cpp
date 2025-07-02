#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using u128 = unsigned __int128;

using a2 = std::array<int, 2>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
// const int mod = 1e9 + 7;
const int mod = 998244353;

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
};

void solve() {
    int n, q;std::cin >> n >> q;
    std::vector<a2> points(n);
    for (auto& [x, y] : points)std::cin >> x >> y;
    auto dis = [&](int i, int j) {return std::abs(points[i][0] - points[j][0]) + std::abs(points[i][1] - points[j][1]);};
    std::priority_queue<a3, std::vector<a3>, std::greater<a3>> pq;
    for (int i = 0;i < n;++i)for (int j = i + 1;j < n;++j) {
        pq.push({ dis(i,j), i, j });
        // std::cout << dis(i, j) << ' ' << i << ' ' << j << '\n';
    }
    dsu d(n + q);
    for (int i = 0;i < q;++i) {
        int op;std::cin >> op;
        if (op == 1) {
            int x, y;std::cin >> x >> y;
            int id = points.size();
            points.push_back({ x,y });
            for (int j = 0;j < id;++j) {
                pq.push({ dis(id, j), id, j });
                // std::cout << dis(id, j) << ' ' << id << ' ' << j << '\n';
            }
        }
        if (op == 2) {
            int ans = -1;
            while (pq.size()) {
                auto [dis, i, j] = pq.top();
                pq.pop();
                if (d.merge(i, j)) {
                    // std::cout << i << ' ' << j << '\n';
                    ans = dis;
                    break;
                }
            }
            while (pq.size()) {
                auto [dis, i, j] = pq.top();
                if (dis == ans) {
                    pq.pop();
                    // std::cout << i << ' ' << j << '\n';
                    d.merge(i, j);
                }
                else break;
            }
            std::cout << ans << '\n';
        }
        if (op == 3) {
            int u, v;std::cin >> u >> v;u--, v--;
            std::cout << (d.get_root(u) == d.get_root(v) ? "Yes" : "No") << '\n';
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