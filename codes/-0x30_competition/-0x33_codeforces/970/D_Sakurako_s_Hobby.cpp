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
    std::vector<int> a(n), vis(n), ans(n);
    for (int& x : a)std::cin >> x, x--;
    std::string s;std::cin >> s;
    std::vector<int> g[n];
    int col = 0;
    auto work = [&](int x) {
        col++;
        std::stack<int> st;
        while (!vis[x]) {
            vis[x] = col;
            st.push(x);
            x = a[x];
        }
        if (vis[x] != col) {
            int cur = ans[x];
            while (st.size()) {
                ans[st.top()] = cur + (s[st.top()] == '0');
                st.pop();
            }
            return;
        }
        int y = x;
        std::vector<int> vt;
        while (st.top() != y) {
            vt.push_back(st.top());
            st.pop();
        }
        vt.push_back(st.top());
        st.pop();
        int cur = 0;
        for (int x : vt)if (s[x] == '0')cur++;
        for (int x : vt)ans[x] = cur;
        while (st.size()) {
            ans[st.top()] = cur + (s[st.top()] == '0');
            st.pop();
        }
        return;
        };
    for (int i = 0;i < n;++i)if (!vis[i])work(i);
    for (int i = 0;i < n;++i)std::cout << ans[i] << " ";
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