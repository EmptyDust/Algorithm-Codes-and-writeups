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

std::vector<int> primes, next;

void sieve(int n) {
    next.assign(n + 1, 1);
    primes.clear();

    for (int i = 2; i <= n; i++) {
        if (next[i] == 1) {
            primes.push_back(i);
            next[i] = i;
        }
        for (auto p : primes) {
            if (i * p > n) {
                break;
            }
            next[i * p] = std::max(p, next[i]);
        }
    }
}

void solve() {
    int n;std::cin >> n;
    std::vector adj(n + 1, std::vector<int>());
    for (int i = 1;i <= n;++i) {
        adj[next[i]].push_back(i);
        // std::cout << next[i] << ' ' << i << '\n';
    }
    std::vector<int> ans(n + 1);
    for (int i = 1;i <= n;++i) if (next[i] == i) {
        int sz = adj[i].size();
        for (int j = 0;j < sz;++j) {
            ans[adj[i][j]] = adj[i][(j + 1) % sz];
        }
    }
    for (int i = 1;i <= n;++i)std::cout << ans[i] << ' ';
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    sieve(1e5 + 10);
    int t;std::cin >> t;
    while (t--) {
        solve();
        std::cout << '\n';
    }
    return 0;
}