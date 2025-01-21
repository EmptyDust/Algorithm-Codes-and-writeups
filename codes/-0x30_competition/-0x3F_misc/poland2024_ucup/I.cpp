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

void solve() {
    int n, k;std::cin >> n >> k;
    std::vector<i64> a(n);
    for (auto& x : a)std::cin >> x;
    ranges::sort(a);
    if (a.front() == a.back()) {
        std::cout << 0 << ' ' << comb(n, k) * comb(n - k, k) % mod * inv(2) % mod << '\n';
        return;
    }
    i64 ans1 = 0, ans2 = 1;
    for (int i = 0;i < k;++i)ans1 -= a[i];
    for (int i = n - k;i < n;++i)ans1 += a[i];

    if (a[k - 1] == a[n - k]) {
        int cnt1 = 0, cnt2 = 0, cntm = 0;
        for (int i = 0;i < n;++i) {
            if (a[i] < a[k - 1])cnt1++;
            if (a[i] == a[k - 1])cntm++;
            if (a[i] > a[k - 1])cnt2++;
        }
        ans2 = comb(cntm, k - cnt1) * comb(cntm - (k - cnt1), k - cnt2) % mod;
        std::cout << ans1 << ' ' << ans2 << '\n';
        return;
    }

    for (int i = 1, cnt = 1, cur = 0;i < n; ++i) {
        if (a[i] != a[i - 1]) {
            if (cnt + cur >= k) {
                int u = k - cur;
                ans2 = ans2 * comb(cnt, u) % mod;
                break;
            }
            cur += cnt;
            cnt = 1;
        }
        else cnt++;
    }
    for (int i = n - 2, cnt = 1, cur = 0;i >= 0; --i) {
        if (a[i] != a[i + 1]) {
            if (cnt + cur >= k) {
                int u = k - cur;
                ans2 = ans2 * comb(cnt, u) % mod;
                break;
            }
            cur += cnt;
            cnt = 1;
        }
        else cnt++;
    }
    std::cout << ans1 << ' ' << ans2 << '\n';
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}