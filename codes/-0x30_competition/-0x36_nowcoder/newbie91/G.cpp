#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9;
using pt = std::pair<int, int>;
using ull = unsigned long long;
std::vector<int> adj[MAXN];

#define M1 998244853
#define M2 1000000009
#define N 500000

i64 qpow(i64 x, i64 p, i64 mod) {
    i64 ret = 1;
    while (p) {
        if (p & 1)ret = ret * x % mod;
        p >>= 1;
        x = x * x % mod;
    }
    return ret;
}

struct hsh {
    i64 w1, w2;
    hsh operator * (const int w) {
        return { w1 * w % M1,w2 * w % M2 };
    }
    hsh operator * (const hsh w) {
        return { w1 * w.w1 % M1,w2 * w.w2 % M2 };
    }
    hsh operator + (const hsh w) {
        return { (w1 + w.w1) % M1,(w2 + w.w2) % M2 };
    }
    hsh operator - (const hsh w) {
        return { (w1 + M1 - w.w1) % M1,(w2 + M2 - w.w2) % M2 };
    }
    bool operator == (const hsh w) {
        return (w1 == w.w1) && (w2 == w.w2);
    }
    i64 wt() {
        return M2 * w1 + w2;
    }
    void show() { std::cout << w1 << ' ' << w2 << '\n'; }
}pw[N + 50], inv[N + 50];

std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());

int dep[MAXN], lg[MAXN], p[MAXN][30];
void init() {
    int b1 = rng() % M1 + 1, b2 = rng() % M2 + 1;
    pw[0] = inv[0] = { 1,1 };
    pw[1] = { b1,b2 };
    inv[1] = { qpow(b1,M1 - 2,M1),qpow(b2,M2 - 2,M2) };
    for (int i = 2;i <= N;i++) {
        pw[i] = pw[i - 1] * pw[1];
        inv[i] = inv[i - 1] * inv[1];
    }
    for (int i = 1;i <= N;++i)
        lg[i] = lg[i >> 1] + 1;
}

int lca(int x, int y) {
    if (dep[x] < dep[y])std::swap(x, y);
    while (dep[x] > dep[y])
        x = p[x][lg[dep[x] - dep[y]] - 1];
    if (x == y)return x;
    for (int k = lg[dep[x]] - 1;k >= 0;--k)
        if (p[x][k] != p[y][k])
            x = p[x][k], y = p[y][k];
    return p[x][0];
}

hsh h1[MAXN], h2[MAXN];
int Fa[MAXN];
std::string s;
void dfs(int x, int par) {
    Fa[x] = par;
    p[x][0] = par;
    dep[x] = dep[par] + 1;
    h1[x] = h1[par] + pw[dep[x]] * s[x];
    h2[x] = h2[par] + inv[dep[x]] * s[x];
    for (int i = 1;i <= lg[dep[x]];++i)
        p[x][i] = p[p[x][i - 1]][i - 1];
    for (int nxt : adj[x])if (nxt != par)dfs(nxt, x);
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int n;std::cin >> n;
    std::cin >> s;s = '#' + s;
    int rt;
    for (int u = 1, v;u <= n;++u) {
        std::cin >> v;
        adj[v].push_back(u);
        if (v == 0)rt = u;
    }
    init();
    dfs(rt, 0);
    int t;std::cin >> t;
    while (t--) {
        int x, y;
        std::cin >> x >> y;
        int z = lca(x, y);
        hsh hash1 = ((h2[x] - h2[z]) * pw[dep[z] * 2] + (h1[y] - h1[Fa[z]])) * pw[dep[x]];
        hsh hash2 = ((h2[y] - h2[z]) * pw[dep[z] * 2] + (h1[x] - h1[Fa[z]])) * pw[dep[y]];
        std::cout << (hash1 == hash2 ? "YES" : "NO") << '\n';
    }
    return 0;
}