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
    std::vector g(2 * n + 1, std::vector<int>());
    for (int i = 0;i < n;++i) {
        int x;std::cin >> x;
        g[x].push_back(i);
    }
    int ans = n; 
    
    std::vector<int> l(n), r(n);
    for (int x = 1;x < 2 * n;++x) {
        {
            std::vector<int> p, q;
            for (auto y : g[x]) if (!l[y]) p.push_back(y);
            for (auto y : g[x + 1]) if (!r[y]) q.push_back(y);
            for (int i = 0, j = 0;i < p.size() && j < q.size();++j) {
                if (p[i] > q[j]) continue;
                l[p[i]] = 1;
                r[q[j]] = 1;
                i++;
                ans--;
            }
        }
        {
            std::vector<int> p, q;
            for (auto y : g[x]) if (!r[y]) p.push_back(y);
            for (auto y : g[x + 1]) if (!l[y]) q.push_back(y);
            // std::cout << p.size() << ' ' << q.size() << '\n';
            ranges::reverse(p);
            ranges::reverse(q);
            for (int i = 0, j = 0;i < p.size() && j < q.size();++j) {
                if (p[i] < q[j]) continue;
                r[p[i]] = 1;
                l[q[j]] = 1;
                // if (x == 3)std::cout << p[i] << ' ' << q[j] << '\n';
                i++;
                ans--;
            }
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