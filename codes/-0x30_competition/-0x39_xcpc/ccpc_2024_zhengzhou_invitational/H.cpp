#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 998244353;
using pt = std::pair<int, int>;

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

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int n;
    std::cin >> n;
    i64 ans = 1, sum = 0, num;
    std::set<int> st;
    std::vector<int> cnt(n + 1, 0);
    for (int i = 0, pre = -1;i < 2 * n;++i) {
        std::cin >> num;
        if (num == -1) {
            int min = *st.begin();
            ans = ans * cnt[min] % mod * inv(sum) % mod;
            //std::cout << min << ' ' << cnt[min] << ' ' << sum << '\n';
            cnt[min]--;
            if (!cnt[min])st.erase(min);
            sum--;
            if (pre != -1 && pre > min) {
                std::cout << 0;
                return 0;
            }
            pre = min;
        }
        else {
            if (!cnt[num])
                st.insert(num);
            sum++;
            cnt[num]++;
        }
    }
    std::cout << ans;
    return 0;
}