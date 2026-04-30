#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;

void solve() {
    int n, x;std::cin >> n >> x;
    std::vector<int> a(n);
    for (int& x : a)std::cin >> x;
    std::set<int> st;st.insert(x);
    int cnt = 1;
    for (int m : a) {
        if (st.count(m)) {
            cnt++;
            st.clear();
            st.insert(x);
        }
        std::vector<int> in;
        for (int t : st) {
            if (t % m == 0)in.push_back(t / m);
        }
        for (int t : in)st.insert(t);
    }
    std::cout << cnt;
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