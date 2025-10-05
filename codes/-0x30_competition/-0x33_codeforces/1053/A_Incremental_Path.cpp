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
    int n, m;std::cin >> n >> m;
    std::string s;std::cin >> s;
    std::vector<int> a(m);
    for (auto& x : a)std::cin >> x;
    auto ans(a);
    int now = 1;
    for (int i = 0, j = 0;i < n;++i) {
        now++;
        while (j < m && a[j] < now) j++;
        if (s[i] == 'B') while (j < m && a[j] == now) now++, j++;
        if (j == m || a[j] != now) ans.push_back(now);
        if (s[i] == 'B') {
            now++;
            while (j < m && a[j] == now) now++, j++;
        }
    }
    ranges::sort(ans);
    std::cout << ans.size() << '\n';
    for (auto x : ans)std::cout << x << " ";
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