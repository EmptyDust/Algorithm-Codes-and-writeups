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

void solve() {
    int n;std::cin >> n;
    std::vector<pii> p(n);
    for (auto& [l, r] : p)std::cin >> l >> r;
    ranges::sort(p);
    int cntb = 0, cnt0 = 0, cnt1 = 0;
    i64 ans = 0;
    std::set<pii> st;
    for (int i = 0;i < n;++i) {
        auto [x, y] = p[i];
        st.insert(p[i]);
        if (i != n - 1 && y == 0 && p[i + 1] == std::pair{ x, 1 }) {
            cntb++;
        }
        if (y)cnt1++;
        else cnt0++;
        if (st.count({ x - 2,y }) && st.count({ x - 1,!y })) {
            ans++;
        }
    }
    ans += 1ll * cntb * (cnt0 - 1 + cnt1 - 1);
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