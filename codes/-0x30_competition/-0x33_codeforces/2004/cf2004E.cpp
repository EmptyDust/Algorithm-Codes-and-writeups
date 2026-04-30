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
    int idx = 1;
    minp.assign(n + 1, 0);
    id.assign(n + 1, 0);
    primes.clear();
    id[1] = idx++;
    minp[1] = 1;

    for (int i = 2; i <= n; i++) {
        if (minp[i] == 0) {
            minp[i] = i;
            primes.push_back(i);
            if (i > 2)id[i] = idx++;
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

// std::vector<int> primes;
// int p[MAXN];
// void init() {
//     for (int i = 2;i <= N;++i)if (!p[i]) {
//         primes.push_back(i);
//         p[i] = i;
//         for (i64 j = 1ll * i * i;j <= N;j += i) {
//             p[j] = i;
//         }
//     }
// }

void solve() {
    int n;std::cin >> n;
    std::vector<int> a(n);
    int xr = 0;
    for (int& x : a) {
        std::cin >> x;
        if (x % 2 == 0)continue;
        // std::cout << x << " ";
        x = id[minp[x]];
        // std::cout << x << "\n";
        xr ^= x;
    }
    std::cout << (xr ? "Alice" : "Bob");
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    sieve(1e7);
    int t;std::cin >> t;
    while (t--) {
        solve();
        std::cout << '\n';
    }
    return 0;
}