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

void solve() {
    int n;i64 x, y;std::cin >> n >> x >> y;
    std::vector<pii> a(n);
    for (auto& [l, r] : a)std::cin >> l >> r;
    ranges::sort(a);
    std::stack<i64> st;
    std::priority_queue<i64, std::vector<i64>, std::greater<i64>> use;
    i64 ans = 0;
    for (auto& [l, r] : a) {
        ans = (ans + (r - l) * y % mod) % mod;
        while (use.size() && use.top() < l) {
            st.push(use.top());
            use.pop();
        }
        use.push(r);
        if (st.size() && (l - st.top()) * y < x) {
            ans = (ans + (l - st.top()) * y % mod) % mod;
            st.pop();
        }
        else {
            ans = (ans + x) % mod;
        }
        // std::cout << l << ' ' << r << ' ' << ans << '\n';
    }
    std::cout << ans;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t = 1;
    while (t--) {
        solve();
        std::cout << '\n';
    }
    return 0;
}