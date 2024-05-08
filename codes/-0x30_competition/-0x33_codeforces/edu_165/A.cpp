#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
int nums[MAXN], n;
using pt = std::pair<int, int>;
std::vector<int> adj[MAXN];

void solve() {
    int n;std::cin >> n;
    for (int i = 1;i <= n;++i)std::cin >> nums[i];
    std::vector<bool> vis(n + 1, false);
    int ans = 3;
    for (int i = 1;i <= n;++i)if (!vis[i]) {
        int x = nums[i];
        int cnt = 1;
        while (x != i) {
            cnt++;
            x = nums[x];
        }
        ans = std::min(ans, cnt);
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