#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<int, int>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
// const int mod = 1e9 + 7;
const int mod = 998244353;

struct TwoSat {
    int n;
    std::vector<std::vector<int>> e;
    std::vector<bool> ans;
    TwoSat(int n) : n(n), e(2 * n), ans(n) {}
    void addEdge(int u, bool f, int v, bool g) {
        e[2 * u + f].push_back(2 * v + g);
    }
    void addClause(int u, bool f, int v, bool g) {
        addEdge(u, !f, v, g);
        addEdge(v, !g, u, f);
    }
    void notClause(int u, bool f, int v, bool g) {
        addClause(u, !f, v, !g);
    }
    bool satisfiable() {
        std::vector<int> id(2 * n, -1), dfn(2 * n, -1), low(2 * n, -1);
        std::vector<int> stk;
        int now = 0, cnt = 0;
        std::function<void(int)> tarjan = [&](int u) {
            stk.push_back(u);
            dfn[u] = low[u] = now++;
            for (auto v : e[u]) {
                if (dfn[v] == -1) {
                    tarjan(v);
                    low[u] = std::min(low[u], low[v]);
                }
                else if (id[v] == -1) {
                    low[u] = std::min(low[u], dfn[v]);
                }
            }
            if (dfn[u] == low[u]) {
                int v;
                do {
                    v = stk.back();
                    stk.pop_back();
                    id[v] = cnt;
                } while (v != u);
                ++cnt;
            }
            };
        for (int i = 0; i < 2 * n; ++i) if (dfn[i] == -1) tarjan(i);
        for (int i = 0; i < n; ++i) {
            if (id[2 * i] == id[2 * i + 1]) return false;
            ans[i] = id[2 * i] > id[2 * i + 1];
        }
        return true;
    }
    std::vector<bool> answer() { return ans; }
};

int n;
std::vector<pii> p;
bool check(int x) {
    TwoSat twosat(n);
    for (int i = 0;i < n;++i)
        for (int j = i + 1;j < n;++j) {
            if (std::abs(p[i].first - p[j].first) < x)
                twosat.notClause(i, 1, j, 1);
            if (std::abs(p[i].first - p[j].second) < x)
                twosat.notClause(i, 1, j, 0);
            if (std::abs(p[i].second - p[j].first) < x)
                twosat.notClause(i, 0, j, 1);
            if (std::abs(p[i].second - p[j].second) < x)
                twosat.notClause(i, 0, j, 0);
        }
    return !twosat.satisfiable();
}

void solve() {
    p.assign(n, {});
    // for (auto& [l, r] : p)std::cin >> l >> r;
    int l = 0, r = 0;
    for (int i = 0;i < n;++i) {
        std::cin >> p[i].first >> p[i].second;
        r = std::max(r, p[i].second + 1);
    }
    while (l < r) {
        auto mid = l + r >> 1;
        if (check(mid))r = mid;
        else l = mid + 1;
    }
    std::cout << l - 1;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    while (std::cin >> n) {
        solve();
        std::cout << '\n';
    }
    return 0;
}