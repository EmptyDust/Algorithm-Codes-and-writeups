#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<i64, i64>;
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

void solve() {
    int n;std::cin >> n;
    std::vector<i64> a(n), pow2(n + 1);
    for (auto& x : a)std::cin >> x;
    i64 sum = 0;
    std::stack<pii> st;
    for (auto x : a){
        i64 cnt = 0;
        while (x % 2 == 0)cnt++, x /= 2;
        while (st.size() && (cnt >= 30 || st.top().first <= x * qpow(2, cnt))){
            cnt += st.top().second;
            sum = ((sum - st.top().first * qpow(2, st.top().second) % mod + st.top().first) % mod + mod) % mod;
            st.pop();
        }
        st.push({ x,cnt });
        sum = (sum + x * qpow(2, cnt) % mod) % mod;
        std::cout << sum << ' ';
    }
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