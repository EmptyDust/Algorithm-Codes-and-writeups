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
    std::string s;std::cin >> s;
    std::vector<int> f(n + 1), vis(26), cnt(26);
    i64 ans = 0;
    for (int i = n - 1;i >= 0;--i) {
        cnt[s[i] - 'a']++;
        if (!vis[s[i] - 'a']) {
            vis[s[i] - 'a'] = 1;
            f[i] = 1;
        }
        f[i] += f[i + 1];
    }
    vis.assign(26, 0);
    for (int i = 0;i < n;++i) {
        if (!vis[s[i] - 'a']) {
            vis[s[i] - 'a'] = 1;
            ans += f[i];
        }
        // std::cout << ans << ' ';
    }
    for (int i = 0;i < 26;++i)if (cnt[i] > 1)ans++;
    std::cout << ans;
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