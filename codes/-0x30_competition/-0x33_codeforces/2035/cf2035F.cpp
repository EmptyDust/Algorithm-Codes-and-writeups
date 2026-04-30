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

i64 encode(i64 x, i64 f) {
    x <<= 1ll;
    x += f;
    return x;
}


void solve() {
    int n, root;
    std::cin >> n >> root;
    root--;
    std::vector<i64> a(n);
    for (auto& x : a)std::cin >> x;
    bool bi = (std::accumulate(a.begin(), a.end(), 0ll) % 2 + 2) % 2;
    std::vector adj(n, std::vector<int>());
    for (int i = 1;i < n;++i) {
        int u, v;std::cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    i64 l = 0, r = 4e18;
    std::vector<i64> times(n);
    auto dfs = [&](auto&& self, int u, int p)->i64 {
        i64 cur = a[u];
        for (int v : adj[u])if (v != p) {
            cur += self(self, v, u);
        }
        i64 minus = std::min(cur, times[u]);
        cur -= minus, times[u] -= minus;
        if (times[u] % 2)cur++;
        // std::cout << u << ' ' << cur << '\n';
        return cur;
        };

    auto check = [&](auto x)->bool {
        for (int i = 0;i < n;++i) {
            times[i] = x / n + (i < x % n);
        }
        // std::cout << times[4] << " ";
        i64 ret = dfs(dfs, root, -1);
        assert(ret % 2 == 0);
        // std::cout << ret << ' ';
        return ret == 0;
        };
    // std::cout << check(3883776955) << ' ';

    while (l < r) {
        auto mid = l + r >> 1;
        if (check(encode(mid, bi)))r = mid;
        else l = mid + 1;
    }
    i64 ans = -1;
    for (i64 i = l, cnt = 0;cnt < n && i >= 0;--i, cnt++) {
        if (check(encode(i, bi))) {
            ans = i;
            while (i >= n && check(encode(i - n, bi))) {
                ans = i -= n;
            }
        }
    }
    std::cout << encode(ans, bi);
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