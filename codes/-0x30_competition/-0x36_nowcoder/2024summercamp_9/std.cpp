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

void solve()
{
    int n;std::cin >> n;
    i64 l, r;std::cin >> l >> r;
    std::set<int> st;
    int ten = qpow(10, n / 2);
    for (int i = 0;i < 10000;++i) {
        if (i * i > r)break;
        st.insert(i * i);
    }
    int cnt = 0;
    for (int i = l;i <= r;++i) {
        int a = i / ten, b = i % ten;
        if (st.count(a) && st.count(b))cnt++;
    }
    std::cout << cnt;
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t = 1;
    while (t--)
    {
        solve();
        std::cout << '\n';
    }
    return 0;
}