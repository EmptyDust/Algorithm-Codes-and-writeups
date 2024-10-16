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

bool is_tree(std::vector<std::vector<int>>& g, pii notuse = { -1,-1 }) {
    int n = g.size();
    dsu d(n);
    for (int u = 0;u < n;++u) {
        for (int v : g[u])if (u > v) {
            if (notuse != pii{ u, v } && notuse != pii{ v, u }) {
                // std::cout << u << ' ' << v << '\n';
                if (!d.merge(u, v))return false;
            }
        }
    }
    return true;
}

std::vector<int> get_cir(std::vector<std::vector<int>>& g) {
    int n = g.size();
    std::vector<int> vis(n, 0);
    std::stack<int> st;
    std::vector<int> huan;
    bool ok = false;
    std::function<void(int, int)> dfs = [&](int u, int p) {
        st.push(u);
        vis[u] = 1;
        for (int v : g[u])if (!ok && v != p) {
            if (vis[v]) {
                ok = true;
                while (st.top() != v) {
                    huan.push_back(st.top());
                    st.pop();
                }
                huan.push_back(v);
                break;
            }
            dfs(v, u);
        }
        if (!ok)
            st.pop();
        };
    dfs(0, -1);
    return huan;
}

int get_hash(std::vector<std::vector<int>>& g, std::map<std::multiset<int>, int>& hash, std::vector<int>& used, int st) {
    std::function<int(int, int)> dfs = [&](int u, int p) {
        std::multiset<int> st;
        for (int v : g[u])if (v != p && !used[v]) {
            st.insert(dfs(v, u));
        }
        if (hash.count(st))return hash[st];
        else return hash[st] = hash.size() + 1;
        };
    return dfs(st, -1);
}

void solve() {
    int n, m;std::cin >> n >> m;
    std::vector g(n, std::vector<int>());
    for (int i = 0;i < m;++i) {
        int u, v;std::cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    if (is_tree(g)) {
        std::cout << "YES";
        return;
    }
    auto h = get_cir(g);
    // for (auto x : h)std::cout << x << " ";
    if (!is_tree(g, { h.front(),h.back() })) {
        std::cout << "NO";
        return;
    }
    std::map<std::multiset<int>, int> hash;
    std::vector<int> used(n);
    for (int x : h)used[x] = 1;
    if (h.size() % 2) {
        int res = get_hash(g, hash, used, h.front());
        for (auto v : h)
            if (res != get_hash(g, hash, used, v))
            {
                std::cout << "NO";
                return;
            }
    }
    else {
        int res1 = get_hash(g, hash, used, h[0]);
        int res2 = get_hash(g, hash, used, h[1]);
        for (int i = 0;i < h.size();i += 2) {
            if (res1 != get_hash(g, hash, used, h[i])) {
                std::cout << "NO";
                return;
            }
        }
        for (int i = 1;i < h.size();i += 2) {
            if (res2 != get_hash(g, hash, used, h[i])) {
                std::cout << "NO";
                return;
            }
        }
    }
    std::cout << "YES";
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t;std::cin >> t;
    while (t--) {
        solve();
        std::cout << '\n';
    }
    return 0;
}