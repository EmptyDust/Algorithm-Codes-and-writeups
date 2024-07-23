#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<i64, i64>;
using a3 = std::array<i64, 3>;

void solve() {
    int n;std::cin >> n;
    std::vector<int> a(n + 1);
    for (int i = 1;i <= n;++i)std::cin >> a[i];
    std::vector<int> adj[n + 1];
    for (int i = 1;i < n;++i) {
        int u, v;std::cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    std::function<a3(int, int)> dfs = [&](int x, int p)->a3 {
        i64 odd = 0, even = a[x];
        int cnt = 1;
        std::vector<a3> oddl, evenl;
        pii odds, evens;
        for (int nxt : adj[x])if (nxt != p) {
            auto [o, e, c] = dfs(nxt, x);
            cnt += c;
            if (c % 2 == 0) {
                if (o > e)odds.first += o, odds.second += e;
                else evens.first += o, evens.second += e;
            }
            else {
                if (o > e) oddl.push_back({ o,e,c });
                else evenl.push_back({ o,e,c });
            }
        }
        odd += evens.second;
        even += odds.first;
        if (oddl.size() || evenl.size()) {
            odd += odds.first;
            even += evens.second;
        }
        else {
            odd += odds.second;
            even += evens.first;
        }

        std::sort(oddl.begin(), oddl.end(), [&](auto a, auto b) {
            return a[0] - a[1] > b[0] - b[1];
            });
        std::sort(evenl.begin(), evenl.end(), [&](auto a, auto b) {
            return a[1] - a[0] > b[1] - b[0];
            });
        int m = std::min(oddl.size(), evenl.size());
        for (int i = 0;i < m;++i) {
            odd += oddl[i][0] + evenl[i][1];
            even += oddl[i][0] + evenl[i][1];
        }
        for (int i = m, j = oddl.size() - 1;i <= j;++i, --j) {
            if (i == j) {
                odd += oddl[i][1];
                even += oddl[j][0];
                break;
            }
            odd += oddl[i][0];
            even += oddl[i][0];
            odd += oddl[j][1];
            even += oddl[j][1];
        }
        for (int i = m, j = evenl.size() - 1;i <= j;++i, --j) {
            if (i == j) {
                odd += evenl[i][1];
                even += evenl[j][0];
                break;
            }
            odd += evenl[i][1];
            even += evenl[i][1];
            odd += evenl[j][0];
            even += evenl[j][0];
        }
        // if (x == 4) {
        //     std::cout << odd << ' ' << even << ' ' << cnt << '\n';
        // }
        return { odd,even,cnt };
        };
    auto [o, r, c] = dfs(1, 0);
    std::cout << o;
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