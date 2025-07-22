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

std::vector<int> cnt(5e6 + 10);

void solve() {
    int n;std::cin >> n;
    std::vector<int> a(n);
    for (auto& x : a)std::cin >> x;
    if (n % 2) {
        std::cout << "YES";
        return;
    }
    if (n == 2) {
        std::cout << (a[0] == a[1] ? "YES" : "NO");
        return;
    }
    std::vector<int> exist;
    for (int x : a) {
        while (x != 1) {
            exist.push_back(minp[x]);
            cnt[minp[x]]++;
            x /= minp[x];
        }
    }
    bool f = 1;
    for (auto y : exist) {
        // if (cnt[y])std::cout << y << ' ' << cnt[y] << '\n';
        if (cnt[y] % 2) {
            f = 0;
        }
        cnt[y] = 0;
    }
    std::cout << (f ? "YES" : "NO");
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    sieve(5e6 + 10);
    int t;std::cin >> t;
    while (t--) {
        solve();
        std::cout << '\n';
    }
    return 0;
}