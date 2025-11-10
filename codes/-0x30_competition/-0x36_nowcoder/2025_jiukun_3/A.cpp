#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using u128 = unsigned __int128;

using a2 = std::array<int, 2>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
// const int mod = 1e9 + 7;
const int mod = 998244353;

void solve() {
    int n;std::cin >> n;
    std::vector<i64> a(n);
    std::multiset<i64> st;
    for (auto& x : a)std::cin >> x, st.insert(x);
    i64 ans = 0;
    while (st.size() > 1) {
        auto min = *st.begin();
        st.erase(st.begin());
        auto min2 = *st.begin();
        st.erase(st.begin());
        ans += (min + 1) * (min2 + 1);
        st.insert(min + min2);
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