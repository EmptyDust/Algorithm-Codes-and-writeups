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

void solve() {
    int n, m;std::cin >> n >> m;
    TwoSat twosat(2 * n);
    for (int i = 0;i < m;++i) {
        int a, b, c;std::cin >> a >> b >> c;
        a--, b--;
        if (c) {
            twosat.addClause(a, 1, a + n, 1);
            twosat.addClause(a, 1, b + n, 0);
            twosat.addClause(b, 0, a + n, 1);
            twosat.addClause(b, 0, b + n, 0);
        }
        else {
            twosat.addClause(a, 0, b, 1);
            twosat.addClause(a + n, 0, b + n, 1);
        }
    }
    if (twosat.satisfiable()) {
        std::cout << "YES\n";
        auto ans = twosat.answer();
        for (int i = 0;i < n;++i) {
            if (ans[i] && ans[i + n])std::cout << "C";
            if (ans[i] && !ans[i + n])std::cout << "A";
            if (!ans[i] && ans[i + n])std::cout << "B";
            if (!ans[i] && !ans[i + n])std::cout << "D";
        }
    }
    else std::cout << "NO";
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t = 1;
    while (t--) {
        solve();
        std::cout << '\n';
    }
    return 0;
}