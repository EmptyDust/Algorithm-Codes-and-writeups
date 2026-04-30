#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

#define int long long

using a2 = std::array<i64, 2>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
// const int mod = 1e9 + 7;
const int mod = 998244353;


void solve() {
    int n, q;std::cin >> n >> q;
    std::vector<int> a(n);
    std::vector<int> cnt(32);
    int Sor = 0;
    for (auto& x : a) {
        std::cin >> x;
        Sor |= x;
        for (int s = 31;s >= 0;--s) {
            if (x >> s & 1) cnt[s]++;
        }
    }
    int popc = 0;
    for (int i = 0;i < 32;++i)if (Sor >> i & 1)popc++;
    std::vector max(32, std::vector<a2>(n));
    for (int s = 0;s < 32;++s) {
        int mask = (1ll << s) - 1;
        for (int i = 0;i < n;++i) {
            if (a[i] >> s & 1) max[s][i][0] = 0;
            else max[s][i][0] = (1ll << s) - (mask & a[i]);
            max[s][i][1] = i;
        }
        ranges::sort(max[s]);
    }
    std::vector<int> vis(n), cur;
    std::vector<int> ans(32);
    for (int s = 0;s < 32;++s) {
        for (int t = s;t >= 0;--t) {
            int p = 0;
            while (p < n && vis[max[t][p][1]]) p++;
            if (p == n) ans[s] += 1 << t;
            else if (max[t][p][0]) {
                ans[s] += max[t][p][0];
                vis[max[t][p][1]] = 1;
                cur.push_back(max[t][p][1]);
            }
        }
        for (auto x : cur) {
            vis[x] = 0;
        }
        cur.clear();
    }
    std::vector<int> fans(32, -1);
    for (int s = 0;s < 32;++s) {
        if (Sor >> s & 1) popc--;
        if (fans[popc + s] == -1) {
            fans[popc + s] = ans[s];
        }
    }
    // for (auto x : fans)std::cout << x << " ";std::cout << '\n';
    while (q--) {
        int x;std::cin >> x;
        for (int i = 0;i < 32;++i) {
            if (fans[i] > x) {
                std::cout << i << '\n';
                break;
            }
        }
    }
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