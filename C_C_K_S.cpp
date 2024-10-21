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

bool isbimap(std::vector<std::vector<int>>& adj, std::vector<int> b){
    int n = adj.size();
    for (int u = 0;u < n;++u){
        // if (adj[u].size() % 2)return false;//完全欧拉图
        for (auto v : adj[u])
            if (b[v] == b[u])
                return false;
    }
    return true;
}

pii cal(std::vector<std::vector<int>>& adj, std::vector<int> b){
    int n = adj.size();
    std::vector<int> color(n, -1);
    int cnt0 = 0, cnt1 = 0;
    std::function<void(int, int)> dfs = [&](int u, int x){
        if (color[u] == -1)color[u] = x;
        else return;
        if (color[u])cnt1 += b[u];
        else cnt0 += b[u];
        for (int v : adj[u])dfs(v, !x);
        };
    dfs(0, 1);
    return pii{ cnt0,cnt1 };
}

void solve() {
    int n, k;std::cin >> n >> k;
    std::vector<int> a(n);
    for (int& x : a)std::cin >> x;
    int m1;std::cin >> m1;
    std::vector adj1(n, std::vector<int>());
    for (int i = 0;i < m1;++i){
        int u, v;std::cin >> u >> v;
        u--, v--;
        adj1[u].push_back(v);
        adj1[v].push_back(u);
    }
    std::vector<int> b(n);
    for (int& x : b)std::cin >> x;
    int m2;std::cin >> m2;
    std::vector adj2(n, std::vector<int>());
    for (int i = 0;i < m2;++i){
        int u, v;std::cin >> u >> v;
        u--, v--;
        adj2[u].push_back(v);
        adj2[v].push_back(u);
    }
    if (std::count(a.begin(), a.end(), 0) != std::count(b.begin(), b.end(), 1)){
        std::cout << "NO";
        return;
    }
    if (std::count(a.begin(), a.end(), 0) == 0 || std::count(a.begin(), a.end(), 1) == 0){
        std::cout << "YES";
        return;
    }
    if (k != 2 && k != 4){
        std::cout << "NO";
        return;
    }
    if (k == 2){
        auto [c1a, c1b] = cal(adj1, a);
        auto [c2a, c2b] = cal(adj2, b);
        // std::cout << c1a << ' ' << c1b << '\n';
        if (c1a == n / 2 - c2b && c1b == n / 2 - c2a || c1a == n / 2 - c2a && c1b == n / 2 - c2b){
            std::cout << "YES";
        }
        else std::cout << "NO";
        return;
    }
    if (isbimap(adj1, a) && isbimap(adj2, b)){
        std::cout << "YES";
    }
    else std::cout << "NO";
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