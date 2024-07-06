#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 998244353;
using pii = std::pair<int, int>;

i64 qpow(i64 x, i64 p) {
    i64 ret = 1;
    while (p) {
        if (p & 1)ret = ret * x % mod;
        p >>= 1;
        x = x * x % mod;
    }
    return ret;
}

int p[MAXN];
void init() {
    for (int i = 2;i <= N;++i)if (!p[i]) {
        p[i] = i;
        for (i64 j = 1ll * i * i;j <= N;j += i) {
            p[j] = i;
        }
    }
}

std::vector<int> primes_cnt[MAXN];
void solve() {
    int n;std::cin >> n;
    std::vector<int> nums(n);
    for (int& x : nums)std::cin >> x;
    std::vector<int> ini;
    for (int x : nums) {
        while (x >= 2) {
            int cur = p[x], cnt = 0;
            while (x % cur == 0)x /= cur, cnt++;
            primes_cnt[cur].push_back(cnt);
            ini.push_back(cur);
        }
    }

    std::sort(ini.begin(), ini.end());
    ini.erase(std::unique(ini.begin(), ini.end()), ini.end());
    std::vector<i64> ans(n, 1);
    for (int x : ini) {
        std::sort(primes_cnt[x].begin(), primes_cnt[x].end(), std::greater<int>());
        for (int i = 0;i < primes_cnt[x].size();++i) {
            ans[i] = ans[i] * qpow(x, primes_cnt[x][i]) % mod;
        }
        primes_cnt[x].clear();
    }

    i64 res = 0;
    for (auto x : ans) {
        res = (res + x) % mod;
    }
    std::cout << res;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    init();
    int t;std::cin >> t;
    while (t--) {
        solve();
        std::cout << '\n';
    }
    return 0;
}