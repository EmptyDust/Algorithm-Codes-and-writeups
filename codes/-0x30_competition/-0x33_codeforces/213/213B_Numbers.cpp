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
const int mod = 1e9 + 7;
// const int mod = 998244353;

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

i64 info[101][101];
i64 dfs(std::vector<int>& a, int p, int cnt) {
    if (p == 9)return cnt >= a[p];
    if (~info[p][cnt]) {
        return info[p][cnt];
    }
    auto& cur = info[p][cnt] = 0;
    for (int i = a[p];i <= cnt;++i) {
        cur = (cur + comb(cnt - (p == 0), i) * dfs(a, p + 1, cnt - i) % mod) % mod;
    }
    return cur;
}

void solve() {
    memset(info, -1, sizeof info);
    int n;std::cin >> n;
    std::vector<int> a(10);
    for (int& x : a)std::cin >> x;
    i64 ans = 0;
    for (int i = 1;i <= n;++i) {
        ans = (ans + dfs(a, 0, i)) % mod;
    }
    std::cout << ans;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t = 1;
    while (t--) {
        solve();
        std::cout << '\n';
    }
    return 0;
}