#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 998244353;
using pii = std::pair<int, int>;

void solve() {
    int n;std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0;i < n;++i)std::cin >> a[i];
    std::multiset<int> st;
    for (int i = 0;i < n;++i) {
        while (st.size()) {
            auto it = st.begin();
            int x = (*st.begin());
            if (x >= a[i])break;
            // std::cout << x << " " << a[i] << '\n';
            st.erase(it);
            st.insert(x + 1);
            a[i]--;
        }
        st.insert(a[i]);
    }
    i64 ans = 1;
    for (int x : st)ans = ans * x % mod;// std::cout << x << " ";
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