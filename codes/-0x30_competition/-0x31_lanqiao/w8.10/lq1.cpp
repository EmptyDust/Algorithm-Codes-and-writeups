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
    std::vector<int> p(n), a(n);
    for (int& x : p)std::cin >> x;
    for (int& x : a)std::cin >> x;
    std::vector<pii> ps(n);
    for (int i = 0;i < n;++i)ps[i] = { p[i],a[i] };
    std::sort(ps.begin(), ps.end());
    int cnt = 0;
    for (int i = 0;i < n;++i) {
        auto [p, s] = ps[i];
        if (!i || ps[i - 1].first < p - s) {
            if (i == n - 1 || ps[i + 1].first > p + s)
                cnt++;
        }
        // std::cout << r << ' ';
    }
    std::cout << cnt << '\n';
    // while (st.size()) {
    //     std::cout << st.top() << ' ';
    //     st.pop();
    // }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}