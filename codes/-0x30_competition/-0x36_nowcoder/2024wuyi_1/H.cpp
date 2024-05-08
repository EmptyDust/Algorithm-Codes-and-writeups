#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
int u, v;
using pt = std::pair<int, int>;
std::vector<int> adj[10];

void solve() {
    for (int i = 1;i <= 6;++i)adj[i].clear();
    std::vector<int> cnt(6, 0);
    for (int i = 1;i <= 5;++i) {
        std::cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        cnt[u - 1]++;
        cnt[v - 1]++;
    }
    {
        int mx = -1;
        for (int x : cnt)
            mx = std::max(mx, x);
        if (mx == 2) {
            std::cout << "n-hexane";
            return;
        }
    }
    {
        for (int x : cnt)if (x == 4) {
            std::cout << "2,2-dimethylbutane";
            return;
        }
    }
    {
        int c = 0;
        for (int x : cnt)if (x == 3)c++;
        if (c == 2) {
            std::cout << "2,3-dimethylbutane";
            return;
        }
    }
    {
        for (int i = 0;i < 6;++i)if (cnt[i] == 3) {
            int x = i + 1;
            int c = 0;
            for (int nxt : adj[x])if (cnt[nxt - 1] == 1)c++;
            if (c == 2) {
                std::cout << "2-methylpentane";
            }
            else {
                std::cout << "3-methylpentane";
            }
            return;
        }
    }
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