#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 998244353;
using pt = std::pair<int, int>;

struct Mi64 {
    i64 value;
    Mi64() {}
    Mi64(i64 value) { this->value = value; }
    Mi64 operator * (const i64 w) {
        return value * w % mod;
    }
    Mi64 operator * (const Mi64 w) {
        return value * w.value % mod;
    }
    Mi64 operator + (const Mi64 w) {
        return (value + w.value) % mod;
    }
    Mi64 operator - (const Mi64 w) {
        return((value - w.value) % mod + mod) % mod;
    }
    bool operator == (const Mi64 w) {
        return value == w.value;
    }
}cnt0[MAXN], sum0[MAXN], cnt1[MAXN], sum1[MAXN], dis[MAXN];

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int n, m;std::cin >> n >> m;
    std::string s;std::cin >> s;s = '~' + s;
    for (int i = 1;i <= n;++i) {
        sum0[i] = sum0[i - 1] + (s[i] == '0' ? i : 0);
        cnt0[i] = cnt0[i - 1] + (s[i] == '0');

        sum1[i] = sum1[i - 1] + (s[i] == '1' ? i : 0);
        cnt1[i] = cnt1[i - 1] + (s[i] == '1');

        if (s[i] == '1')dis[i] = dis[i - 1] + (cnt0[i] * i - sum0[i]);
        else dis[i] = dis[i - 1] + (cnt1[i] * i - sum1[i]);
    }
    int l, r;
    while (m--) {
        std::cin >> l >> r;
        int len = r - l + 1;
        Mi64 ans = dis[r] - dis[l - 1];
        ans = ans - (cnt0[r] - cnt0[l - 1]) * (cnt1[l - 1] * (l - 1) - sum1[l - 1]);
        ans = ans - (cnt1[r] - cnt1[l - 1]) * (cnt0[l - 1] * (l - 1) - sum0[l - 1]);
        ans = ans - (sum0[r] - sum0[l - 1] - (cnt0[r] - cnt0[l - 1]) * (l - 1)) * cnt1[l - 1];
        ans = ans - (sum1[r] - sum1[l - 1] - (cnt1[r] - cnt1[l - 1]) * (l - 1)) * cnt0[l - 1];
        std::cout << ans.value << '\n';
    }
    return 0;
}