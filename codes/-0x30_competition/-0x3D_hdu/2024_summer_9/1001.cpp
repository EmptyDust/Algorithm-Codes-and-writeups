#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<i64, i64>;
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

void solve() {
    int n, k;std::cin >> n >> k;
    std::vector<int> g[n + 1];
    for (int i = 2;i <= n;++i) {
        int p;std::cin >> p;
        g[p].push_back(i);
    }
    std::vector<std::array<pii, 2>> value(n + 1);//pii [cnt,cur]
    i64 ans = 1;
    std::function<void(int, int)> dfs = [&](int u, int dep) {
        auto& res = value[u];
        for (int v : g[u]) {
            dfs(v, dep + 1);
            auto chi = value[v];
            if (chi[0].second == chi[1].second) {
                
            }

            cnt0 += c0;
            cnt1 += c1;
        }
        if (cnt0 == cnt1)ans = ans * 2 % mod;
        else if (cnt0 < cnt1)cnt0++;
        else cnt1++;
        };
    dfs(1, 0);
    ans = qpow(ans, k);
    std::cout << ans;
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