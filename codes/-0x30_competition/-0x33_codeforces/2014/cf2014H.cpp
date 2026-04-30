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
    int n, q;std::cin >> n >> q;
    std::map<int, u64> mp;
    std::vector<u64> a(n + 1);
    for (int i = 1;i <= n;++i) {
        std::cin >> a[i];
        if (mp.count(a[i]))a[i] = mp[a[i]];
        else a[i] = mp[a[i]] = rng();
        a[i] ^= a[i - 1];
        // std::cout << a[i] << " ";
    }
    for (int i = 0;i < q;++i) {
        int l, r;std::cin >> l >> r;
        std::cout << (a[l - 1] ^ a[r] ? "NO" : "YES") << '\n';
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