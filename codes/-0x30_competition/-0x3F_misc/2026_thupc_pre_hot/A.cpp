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
    int n, m;std::cin >> n >> m;
    std::vector map(n, std::vector<int>(m));
    for (int i = 0;i < n;++i) {
        std::string s;std::cin >> s;
        for (int j = 0;j < m;++j) {
            map[i][j] = s[j] == '1';
        }
    }
    std::vector<int> a(n), b(m);
    for (int i = 0;i < n;++i) {
        bool f = 0;
        for (int j = 0;j < m;++j) {
            f ^= map[i][j];
        }
        a[i] = f;
    }
    for (int j = 0;j < m;++j) {
        bool f = 0;
        for (int i = 0;i < n;++i) {
            f ^= map[i][j];
        }
        b[j] = f;
    }
    int ans = 0;
    for (int i = 0;i < n;++i) {
        for (int j = 0;j < m;++j) {
            if (a[i] && b[j]) {
                ans++;
                a[i] = !a[i];
                b[j] = !b[j];
            }
        }
    }
    ans += std::accumulate(a.begin(), a.end(), 0) + std::accumulate(b.begin(), b.end(), 0ll);
    std::cout << ans;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t = 1; std::cin >> t;
    while (t--) {
        solve();
        std::cout << '\n';
    }
    return 0;
}