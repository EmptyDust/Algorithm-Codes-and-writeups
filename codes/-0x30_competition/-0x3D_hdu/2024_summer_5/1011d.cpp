#include <bits/stdc++.h>

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


void solve() {
    int n;std::cin >> n;
    std::vector<bool> vt(n);
    std::set<std::vector<bool>> st;
    std::function<void(std::vector<bool>)> dfs = [&](std::vector<bool> vt) {
        if (st.count(vt))return;
        st.insert(vt);
        for (int i = 0;i < n;++i) {
            std::vector<bool> d(vt);
            d[i] = !d[i];
            if (i)d[i - 1] = !d[i - 1];
            if (i < n - 1)d[i + 1] = !d[i + 1];
            dfs(d);
        }
        };
    dfs(vt);
    std::cout << st.size();
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