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
    std::vector<int> a(n), idx(n), vis(n);
    for (auto& x : a)std::cin >> x;
    std::iota(idx.begin(), idx.end(), 0);
    ranges::sort(idx, [&](int x, int y) {return a[x] > a[y];});
    std::set<a2, std::greater<a2>> st;
    int pos = 0, ans = 0;
    while (pos < n) {
        while (pos < n && st.size() && (*st.begin())[0] == a[idx[pos]]) {
            auto [value, x] = *st.begin();
            vis[x] = 1;
            st.erase(st.begin());
            if (x && !vis[x - 1])st.insert({ a[x - 1],x - 1 });
            if (x < n - 1 && !vis[x + 1])st.insert({ a[x + 1],x + 1 });
            while (pos < n && vis[idx[pos]]) {
                pos++;
            }
        }
        if (pos < n) {
            ans++;
            st.insert({ a[idx[pos]],idx[pos] });
        }
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