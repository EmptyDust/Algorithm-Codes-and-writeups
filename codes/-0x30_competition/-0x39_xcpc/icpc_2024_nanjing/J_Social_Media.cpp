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
    int n, m, k;std::cin >> n >> m >> k;
    std::vector<int> a(k), c(k);
    for (int i = 0;i < n;++i){
        int x;std::cin >> x;
        x--;
        a[x] = 1;
    }
    std::vector adj(k, std::map<int, int>());
    int base = 0, max = 0;
    for (int i = 0;i < m;++i){
        int u, v;std::cin >> u >> v;
        u--, v--;
        if (a[u] && a[v]){
            base++;
            continue;
        }
        if (u == v){
            c[u]++;
            continue;
        }
        adj[u][v]++;
        adj[v][u]++;
    }
    std::priority_queue<pii> pq;
    for (int i = 0;i < k;++i)if (!a[i]){
        for (auto [x, c_] : adj[i])
            if (a[x])
                c[i] += c_;
        pq.push({ c[i],i });
    }
    // std::cout << c[4] << ' ';
    int ans = base;
    for (int i = 0;i < k;++i)if (!a[i]){
        int max = 0;
        for (auto [x, c_] : adj[i]){
            if (!a[x]){
                max = std::max(max, c[x] + c_);
            }
        }
        if (pq.top().second == i){
            auto tmp = pq.top();
            pq.pop();
            if (pq.size())max = std::max(max, pq.top().first);
            pq.push(tmp);
        }
        else{
            max = std::max(max, pq.top().first);
        }
        // std::cout << i + 1 << ' ' << c[i] << ' ' << max << '\n';
        ans = std::max(ans, base + c[i] + max);
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