#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 998244353;
using pii = std::pair<int, int>;
std::vector<int> adj[MAXN];

struct Mi64 {
    i64 value;
    Mi64() {}
    Mi64(i64 value) { this->value = value; }
    Mi64 operator * (const i64 w) {
        return value * w % mod;
    }
    Mi64 operator * (const Mi64 w) {
        return value * w.value % mod;
    }
    Mi64 operator + (const Mi64 w) {
        return (value + w.value) % mod;
    }
    Mi64 operator - (const Mi64 w) {
        return((value - w.value) % mod + mod) % mod;
    }
    bool operator == (const Mi64 w) {
        return value == w.value;
    }
};

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

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int n;std::cin >> n;
    for (int i = 1;i < n;++i) {
        int u, v;std::cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    std::vector<i64> cnt(n + 1), leaf(n + 1);
    std::function<void(int, int, int)> dfs = [&](int x, int p, int depth)->void {
        cnt[depth]++;
        if (adj[x].size() == 1 && p != 0)leaf[depth]++;
        for (int nxt : adj[x])if (nxt != p) {
            dfs(nxt, x, depth + 1);
        }
        };
    dfs(1, 0, 0);
    Mi64 cur = 1, ans = 0;
    for (i64 i = 1;i <= n;++i) {
        Mi64 p = cur * leaf[i] * inv(cnt[i]);
        ans = ans + p * i;
        cur = cur - p;
    }
    std::cout << ans.value;
    return 0;
}