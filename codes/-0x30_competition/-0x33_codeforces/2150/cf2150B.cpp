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

i64 qpow(i64 x, i64 p) {
    i64 ret = 1;
    while (p) {
        if (p & 1)ret = ret * x % mod;
        p >>= 1;
        x = x * x % mod;
    }
    return ret;
}

#define inv(x) qpow(x,mod-2)

std::vector<int> fact(1, 1);
std::vector<int> inv_fact(1, 1);
i64 comb(int n, int k) {
    if (k<0 || k>n)return 0;
    while ((int)fact.size() < n + 1) {
        fact.push_back(1ll * fact.back() * (int)fact.size() % mod);
        inv_fact.push_back(inv(fact.back()));
    }
    return 1ll * fact[n] * inv_fact[k] % mod * inv_fact[n - k] % mod;
}

void solve() {
    int n;std::cin >> n;
    std::vector<int> a(n);
    for (auto& x : a)std::cin >> x;
    if (std::accumulate(a.begin(), a.end(), 0) != n) {
        std::cout << 0;
        return;
    }
    for (int i = (n + 1) / 2;i < n;++i) {
        if (a[i] != 0) {
            std::cout << 0;
            return;
        }
    }
    i64 ans = 1;
    for (int i = n / 2 - (n % 2 == 0), j = n / 2, cnt = 0;i >= 0 && j < n;--i, ++j) {
        cnt += i == j ? 1 : 2;
        if (a[i] > cnt) {
            std::cout << 0;
            return;
        }
        ans = ans * comb(cnt, a[i]) % mod;
        // std::cout << i << ' ' << j << ' ' << cnt << " " << ans << "\n";
        cnt -= a[i];
    }
    std::cout << ans;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t;std::cin >> t;
    while (t--) {
        solve();
        std::cout << '\n';
    }
    return 0;
}