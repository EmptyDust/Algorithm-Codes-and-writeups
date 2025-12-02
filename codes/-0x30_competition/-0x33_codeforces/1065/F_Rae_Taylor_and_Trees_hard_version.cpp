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
    std::vector<int> a(n + 1), vis(n + 1);
    std::set<a2> set;
    for (int i = 1;i <= n;++i) {
        std::cin >> a[i];
        set.insert({ a[i], i });
    }
    std::vector<a2> ans;
    for (int i = n;i >= 1;--i) if (!vis[i]) {
        int minp = i;
        while (set.size() && (*set.begin())[0] <= a[i]) {
            auto [x, p] = *set.begin();
            set.erase(set.begin());
            if (p > i) {
                std::cout << "No\n";
                return;
            }
            if (x != a[i]) ans.push_back({ x, a[i] });
            minp = std::min(minp, p);
            vis[p] = 1;
        }
        set.insert({ a[minp], minp });
        // for (auto [x, y] : set)std::cout << x << ' ' << y << '\n';
        // std::cout << '\n';
    }
    assert(ans.size() == n - 1);
    std::cout << "Yes\n";
    for (auto [x, y] : ans) std::cout << x << " " << y << '\n';
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t;std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}