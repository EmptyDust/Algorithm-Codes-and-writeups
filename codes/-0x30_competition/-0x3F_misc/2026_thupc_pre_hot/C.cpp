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
    // 2: 2
    // 3: 2 1 3
    // 4: 2 1 3 4
    // 5: 3 2 4 1 5
    int n;std::cin >> n;
    int mid = (n + 1) / 2;
    auto valid = [&](int x) ->bool {
        if (x <= 1 || x > n) return false;
        int limit = std::sqrt(x);
        for (auto y : primes) {
            // std::cout << y << ' ';
            if (y > limit) break;
            if (x % y == 0) return false;
        }
        return true;
        };
    // std::cout << valid(4) << ' ';
    for (int d = 0;;++d) {
        if (valid(mid - d)) {
            mid -= d;
            break;
        }
        if (valid(mid + d)) {
            mid += d;
            break;
        }
    }
    std::cout << mid << ' ';
    for (int d = 1;mid + d <= n || mid - d >= 1;++d) {
        if (mid - d >= 1) std::cout << mid - d << ' ';
        if (mid + d <= n) std::cout << mid + d << ' ';
    }
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