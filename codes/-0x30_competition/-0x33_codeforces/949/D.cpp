#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pt = std::pair<int, int>;
std::vector<int> minp, primes;

void sieve(int n) {
    minp.assign(n + 1, 0);
    primes.clear();

    for (int i = 2; i <= n; i++) {
        if (minp[i] == 0) {
            minp[i] = i;
            primes.push_back(i);
        }

        for (auto p : primes) {
            if (i * p > n) {
                break;
            }
            minp[i * p] = p;
            if (p == minp[i]) {
                break;
            }
        }
    }
}

void solve() {
    int n;std::cin >> n;
    int m = 1;
    while (n - 1 > (m % 2 == 1 ? m * (m + 1) / 2 : m * m / 2 + 1))m++;

    std::vector<int> ans;ans.reserve(n);
    std::vector<std::vector<bool>> adj(m, std::vector<bool>(m, 1));
    std::vector<int> cur(m);
    if (m % 2 == 0)for (int i = 1;i < m - 1;i += 2)adj[i][i + 1] = adj[i + 1][i] = 0;

    auto dfs = [&](auto&& self, int x)->void {
        for (int& i = cur[x];i < m;++i) {
            if (adj[x][i]) {
                adj[x][i] = adj[i][x] = 0;
                self(self, i);
            }
        }
        ans.push_back(primes[x]);
        };
    dfs(dfs, 0);

    ans.resize(n);
    for (int x : ans)std::cout << x << ' ';
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    sieve(3e5);
    int t;std::cin >> t;
    while (t--) {
        solve();
        std::cout << '\n';
    }
    return 0;
}