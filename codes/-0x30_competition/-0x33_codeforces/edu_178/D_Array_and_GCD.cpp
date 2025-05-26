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
    std::vector<i64> a(n), b(n);
    b[0] = primes[0];
    // std::cout << b[0] << ' ';
    for (int i = 1;i < n;++i)b[i] = b[i - 1] + primes[i];
    for (auto& x : a)std::cin >> x;
    ranges::sort(a, std::greater<i64>());
    for (int i = 1;i < n;++i)a[i] += a[i - 1];
    ranges::reverse(a);
    ranges::reverse(b);
    for (int i = 0;i < n;++i) {
        if (a[i] >= b[i]) {
            std::cout << i;
            return;
        }
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    sieve(6e6);
    // std::cout << primes.size() << '\n';
    int t;std::cin >> t;
    while (t--) {
        solve();
        std::cout << '\n';
    }
    return 0;
}