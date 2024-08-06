#include <bits/stdc++.h>

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
    std::vector<int> a(n + 1);
    for (int i = 1;i <= n;++i)std::cin >> a[i];
    std::vector<int> ans(n + 1, inf);ans[0] = 0;
    for (int i = 1;i <= n;++i) {
        for (int j = std::max(0, i - a[i]);j < i && j + a[i] <= n;++j) {
            ans[j + a[i]] = std::min(ans[j + a[i]], ans[j] + 1);
            // std::cout << j << ' ';
        }
    }
    std::cout << (ans[n] == inf ? -1 : ans[n]);
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