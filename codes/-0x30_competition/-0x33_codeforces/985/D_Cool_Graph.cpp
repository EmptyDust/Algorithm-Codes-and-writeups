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
    std::vector<a3> ans;
    std::vector<int> a(n);
    for (int i = 0;i < m;++i) {
        int u, v;std::cin >> u >> v;
        u--, v--;
        if (u && v) {
            ans.push_back({ 0,u,v });
            a[u] ^= 1;
            a[v] ^= 1;
        }
        else if (u)a[u] ^= 1;
        else if (v)a[v] ^= 1;
    }
    a[0] = std::accumulate(a.begin(), a.end(), 0);
    if (a[0]) {
        pii e;
        for (int i = 1;i < n;++i)if (a[i]) {
            e = { 0,i };
            break;
        }
        for (int i = 1;i < n;++i) if (!a[i]) {
            auto [u, v] = e;
            ans.push_back({ u,v,i });
            e = { u,i };
        }
    }
    std::cout << ans.size() << '\n';
    for (auto [a, b, c] : ans)
        std::cout << a + 1 << " " << b + 1 << ' ' << c + 1 << '\n';
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