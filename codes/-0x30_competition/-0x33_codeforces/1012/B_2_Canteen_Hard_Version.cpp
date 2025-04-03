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
    int n;i64 k;std::cin >> n >> k;
    std::vector<int> a(n), b(n);
    for (auto& x : a)std::cin >> x;
    for (auto& x : b)std::cin >> x;
    std::reverse(a.begin(), a.end());
    std::reverse(b.begin(), b.end());
    auto l = 0, r = n;
    auto check = [&](auto X)->bool {
        i64 ret = 0;
        std::queue<pii> q;
        std::stack<pii> st;
        for (int i = 0;i < n;++i) {
            q.push({ a[i],i });
        }
        int i = 0, ans = 0;
        std::vector<int> res(n);
        while (q.size()) {
            if (i < n) st.push({ b[i],i });
            auto [x, xpos] = q.front();
            q.pop();
            while (x && st.size()) {
                auto& [y, ypos] = st.top();
                int cnt = xpos - ypos + 1;
                if (cnt > X) {
                    ret += x;
                    x = 0;
                    break;
                }
                if (y >= x) {
                    ans = std::max(ans, cnt);
                    res[xpos % n] = cnt;
                    y -= x;
                    x = 0;
                    break;
                }
                else {
                    x -= y;
                    st.pop();
                }
            }
            if (x) q.push({ x,xpos + n });
            ++i;
        }
        // for (int& x : res)std::cout << x << ' ';std::cout << '\n';
        // std::cout << X << ' ' << ret << '\n';
        return ret <= k;
        };
    while (l < r) {
        auto mid = l + r >> 1;
        if (check(mid))r = mid;
        else l = mid + 1;
    }
    std::cout << l;
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