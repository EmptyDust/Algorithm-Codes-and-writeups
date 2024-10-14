#include <bits/stdc++.h>

using i64 = long long;

const int mod = 998244353;
const int MAXN = 3e5 + 10;

i64 BIT[MAXN];
int n;
void init() {
    for (int i = 0;i <= n;++i)BIT[i] = 0;
}
void add(int p, i64 x) {
    for (int i = p;i <= n;i += i & -i) {
        BIT[i] = (BIT[i] + x) % mod;
    }
}
i64 query(int p) {
    i64 res = 0;
    for (int i = p;i > 0;i -= i & -i) {
        res = (res + BIT[i]) % mod;
    }
    return res;
}

void solve() {
    std::cin >> n;
    std::vector<int> a(n + 1);
    for (int i = 1;i <= n;++i)std::cin >> a[i];
    auto b(a);
    std::sort(b.begin() + 1, b.end());
    std::unordered_map<int, int>mp;
    for (int i = 1;i <= n;++i)mp[b[i]] = i;
    for (int i = 1;i <= n;++i)a[i] = mp[a[i]];
    std::vector<i64> pre(n + 1), suf(n + 1);
    for (int i = 1;i <= n;++i) {
        pre[i] = 1 + query(a[i] - 1);
        add(a[i], pre[i]);
    }
    init();
    for (int i = n;i >= 1;--i) {
        suf[i] = 1 + query(a[i] - 1);
        add(a[i], suf[i]);
    }
    i64 ans = 0;
    for (int i = 1;i <= n;++i) {
        ans = (ans + pre[i] * suf[i] % mod) % mod;
    }
    // std::cout << pre[2] << ' ' << suf[2] << ' ';
    std::cout << ans;
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