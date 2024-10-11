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

std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int n, m;std::cin >> n >> m;
    std::vector<u64> a(n + 2);
    for (int i = 0;i < m;++i) {
        int l, r;std::cin >> l >> r;
        u64 sign = rng();
        a[l] ^= sign;
        a[r + 1] ^= sign;
    }
    std::map<u64, int> mp;
    for (int i = 1;i <= n;++i) {
        a[i] ^= a[i - 1];
        mp[a[i]]++;
    }
    for (int i = 1;i <= n;++i) {
        std::cout << mp[a[i]] << " \n"[i == n];
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t;std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}