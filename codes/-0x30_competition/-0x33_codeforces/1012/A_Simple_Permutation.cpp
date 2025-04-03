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
    int mid = 1;
    for (int i = 1;i <= n;++i)if (i == minp[i]) {
        if (std::abs(mid - n / 2) > std::abs(i - n / 2))mid = i;
    }
    std::vector<int> vis(n + 1);
    vis[mid] = 1;
    std::cout << mid << ' ';
    for (int i = 1;i <= n;++i) {
        if (mid + i <= n)std::cout << mid + i << ' ', vis[mid + i] = 1;
        else break;
        if (mid - i >= 1)std::cout << mid - i << ' ', vis[mid - i] = 1;
        else break;
    }
    for (int i = 1;i <= n;++i)if (!vis[i])std::cout << i << ' ';
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