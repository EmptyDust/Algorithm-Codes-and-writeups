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

std::vector<int> minp, primes, id;

void sieve(int n) {
    minp.assign(n + 1, 0);
    id.assign(n + 1, 0);
    primes.clear();

    for (int i = 2; i <= n; i++) {
        if (minp[i] == 0) {
            id[i] = 1;
            minp[i] = i;
            primes.push_back(i);
        }

        for (auto p : primes) {
            if (i * p > n) {
                break;
            }
            minp[i * p] = p;
            id[i * p] = std::max(id[i * p], id[i] + 1);
            if (p == minp[i]) {
                break;
            }
        }
    }
}

void solve() {
    int n, m;std::cin >> n >> m;
    std::vector<int> a(m);
    for (int& x : a)std::cin >> x;
    ranges::sort(a, std::greater<int>());
    std::vector<int> ans(n);
    for (int i = 0;i < n;++i) {
        if (id[i + 1] >= m) {
            std::cout << -1;
            return;
        }
        ans[i] = a[id[i + 1]];
    }

    // for (int x : ans)std::cout << x << ' ';
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    sieve(1e5);
    int t;std::cin >> t;
    while (t--) {
        solve();
        std::cout << '\n';
    }
    return 0;
}