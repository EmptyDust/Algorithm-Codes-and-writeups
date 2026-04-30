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
const int M = 1000;
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
    std::vector<int> a(n);
    for (int& x : a)std::cin >> x;
    int ans = -1;
    for (int i = 0;i < n;++i) {
        if (minp[a[i]] == a[i]) {
            if (ans == -1)ans = a[i];
            else {
                std::cout << -1;
                return;
            }
        }
    }
    if (ans == -1) {
        std::cout << 2;
        return;
    }
    for (int i = 0;i < n;++i) {
        if (a[i] == ans)continue;
        if (a[i] < 2 * ans) {
            std::cout << -1;
            return;
        }
        if (minp[a[i]] == 2)continue;
        int x = a[i] - minp[a[i]];
        if (x < 2 * ans) {
            std::cout << -1;
            return;
        }
    }
    std::cout << ans;
}

// 0   2 3 4 5 6 7

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    sieve(4e5 + 10);
    int t;std::cin >> t;
    while (t--) {
        solve();
        std::cout << '\n';
    }
    return 0;
}