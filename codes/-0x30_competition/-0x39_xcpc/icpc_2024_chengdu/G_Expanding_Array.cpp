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
    std::vector<int> a(n);
    for (int& x : a)std::cin >> x;
    std::set<int> st;
    st.insert(0);

    auto cal = [&](int x, int y) {
        st.insert(x);st.insert(y);
        int b = x | y;st.insert(b);
        int c = x & y;st.insert(c);

        int e = b ^ x;st.insert(e);
        int f = b ^ y;st.insert(f);
        int g = c ^ x;st.insert(g);
        int h = c ^ y;st.insert(h);
        };
    for (int i = 0;i < n - 1;++i) {
        int x = a[i], y = a[i + 1];
        cal(x, y);
        int d = x ^ y;

        cal(x, d);
        cal(d, y);
    }
    // for (auto x : st)std::cout << x << " ";
    std::cout << st.size();
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