#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 5e3, MAXN = 5e3 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<i64, i64>;

std::vector<int> adj[MAXN];
i64 a[MAXN], sum[MAXN], isleave[MAXN];

std::priority_queue<pii, std::vector<pii>, std::greater<pii>> cost[MAXN];

i64 ans = 0;
i64 dfs(int x, int p) {
    for (int nxt : adj[x])if (nxt != p) {
        sum[x] += dfs(nxt, x);
    }

    if (adj[x].size() == 1 && x != 1) {
        isleave[x] = 1;
    }


    if (!isleave[x] && sum[x] < a[x]) {
        i64 c = a[x] - sum[x];
        //std::cout << c << ' ' << x << '\n';
        while (cost[x].size() && c) {
            auto [cst, canuse] = cost[x].top();
            cost[x].pop();
            if (canuse == -1) {
                ans += c * cst;
                while (cost[x].size())
                    cost[x].pop();
                cost[x].push({ cst,-1 });
                c = 0;
            }
            else if (canuse > c) {
                ans += c * cst;
                cost[x].push({ cst,canuse - c });
                c = 0;
            }
            else {
                ans += canuse * cst;
                c -= canuse;
            }
        }
    }

    while (cost[x].size()) {
        auto [cst, canuse] = cost[x].top();
        cost[x].pop();
        cost[p].push({ cst + 1,canuse });
    }

    if (isleave[x]) {
        cost[p].push({ 1,-1 });
    }
    if (sum[x] > a[x]) {
        cost[p].push({ 1,sum[x] - a[x] });
    }

    return a[x];
}

void solve() {
    int n;std::cin >> n;

    ans = 0;
    for (int i = 0;i <= n;++i) {
        adj[i].clear();
        while (cost[i].size())
            cost[i].pop();
        isleave[i] = false;
        sum[i] = 0;
        a[i] = 0;
    }

    for (int i = 1;i <= n;++i)std::cin >> a[i];
    for (int i = 2;i <= n;++i) {
        int p;std::cin >> p;
        adj[p].push_back(i);
        adj[i].push_back(p);
    }
    dfs(1, 0);
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