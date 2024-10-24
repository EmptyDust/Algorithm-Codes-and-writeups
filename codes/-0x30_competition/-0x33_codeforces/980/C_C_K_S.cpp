#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<int, int>;
using a2 = std::array<int, 2>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
// const int mod = 1e9 + 7;
const int mod = 998244353;

std::vector<pii> cal(std::vector<std::vector<int>>& adj, std::vector<int>& a, int k){
    int n = adj.size();
    std::vector<pii> res(k);
    std::vector<int> vis(n);
    std::function<void(int, int)> dfs = [&](int u, int p){
        if (vis[u])return;
        vis[u] = 1;
        if (a[u])
            res[p].first++;
        else res[p].second++;
        for (int v : adj[u])
            dfs(v, (p + 1) % k);
        };
    dfs(0, 0);
    return res;
}

std::vector<int> z_function(std::vector<int> s) {
    int n = (int)s.size();
    std::vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r && z[i - l] < r - i + 1) {
            z[i] = z[i - l];
        }
        else {
            z[i] = std::max(0, r - i + 1);
            while (i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];
        }
        if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
    }
    return z;
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
    }
    auto num1 = cal(adj1, a, k);
    std::vector<int> b(n);
    for (int& x : b)std::cin >> x;
    int m2;std::cin >> m2;
    std::vector adj2(n, std::vector<int>());
    for (int i = 0;i < m2;++i){
        int u, v;std::cin >> u >> v;
        u--, v--;
        adj2[u].push_back(v);
    }
    if (std::count(a.begin(), a.end(), 0) != std::count(b.begin(), b.end(), 1)){
        std::cout << "NO";
        return;
    }
    if (std::count(a.begin(), a.end(), 0) == 0 || std::count(a.begin(), a.end(), 1) == 0){
        std::cout << "YES";
        return;
    }
    auto num2 = cal(adj2, b, k);

    std::vector<int> s(k), t(k);
    for (int i = 0;i < k;++i){
        auto [x1, y1] = num1[i];
        s[(i + 1) % k] += x1 * n;
        s[(i - 1 + k) % k] += y1;

        auto [x2, y2] = num2[i];
        t[i] += x2;
        t[i] += y2 * n;
    }

    s.push_back(-1);
    s.insert(s.end(), t.begin(), t.end());
    s.insert(s.end(), t.begin(), t.end());

    auto z = z_function(s);
    for (int i = k + 1;i <= 3 * k;++i){
        if (z[i] == k){
            std::cout << "YES";
            return;
        }
    }
    std::cout << "NO";
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