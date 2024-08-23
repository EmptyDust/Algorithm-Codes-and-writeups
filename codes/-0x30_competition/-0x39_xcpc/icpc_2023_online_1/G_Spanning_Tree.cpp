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

i64 qpow(i64 x, i64 p) {
    i64 ret = 1;
    while (p) {
        if (p & 1)ret = ret * x % mod;
        p >>= 1;
        x = x * x % mod;
    }
    return ret;
}

#define inv(x) qpow(x,mod-2)

struct dsu {
    std::vector<int> d, cnt;
    dsu(int n) { d.resize(n); iota(d.begin(), d.end(), 0);cnt.assign(n, 1); }
    int get_root(int x) { return d[x] = (x == d[x] ? x : get_root(d[x])); };
    bool merge(int u, int v) {
        if (get_root(u) != get_root(v)) {
            cnt[get_root(v)] += cnt[get_root(u)];
            d[get_root(u)] = get_root(v);
            return true;
        }
        else return false;
    }
    i64 get_size(int u) { return cnt[u]; }
};

std::vector<int> adj[MAXN];
dsu d(MAXN);
i64 merge(int u, int v) {//u->v
    bool ok = false;
    if (adj[u].size() > adj[v].size()) {
        for (auto& x : adj[v]) {
            if (d.get_root(u) == d.get_root(x)) {
                ok = true;
                break;
            }
        }
    }
    else {
        for (auto& x : adj[u]) {
            if (d.get_root(v) == d.get_root(x)) {
                ok = true;
                break;
            }
        }
    }
    if (!ok)return 0;
    i64 ret = inv(d.get_size(u) * d.get_size(v) % mod);
    if (adj[u].size() > adj[v].size())std::swap(adj[u], adj[v]);
    for (auto& x : adj[u])adj[v].push_back(x);
    adj[u].clear();
    d.merge(u, v);
    return ret;
}

void solve() {
    int n;std::cin >> n;
    std::vector<pii> ops(n - 1);
    for (auto& [x, y] : ops)std::cin >> x >> y;
    for (int i = 1;i < n;++i) {
        int u, v;std::cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    i64 ans = 1;
    for (auto& [x, y] : ops) {
        ans = ans * merge(d.get_root(x), d.get_root(y)) % mod;
        if (ans == 0)break;
    }
    std::cout << ans;
    // std::cout << '\n' << inv(2) * inv(3) % mod;
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