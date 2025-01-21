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
    std::vector<pii> info(n);
    for (auto& [op, sta] : info) {
        std::string s, t;std::cin >> s >> t;
        op = s == "set";
        sta = t == "true";
    }
    std::vector<int> q1, q2, q3;
    int m;std::cin >> m;
    std::vector adj(n, std::vector<int>());
    std::vector<int> ok(n), ans, limit(n);
    for (int i = 0;i < m;++i) {
        int u, v;std::cin >> u >> v;u--, v--;
        adj[u].push_back(v);
        limit[v]++;
    }
    for (int i = 0;i < n;++i)if (!limit[i])q1.push_back(i);
    int ch = -1;
    for (int i = 0;i < q1.size();++i) {
        int x = q1[i];
        if (ok[x])continue;
        auto [o, s] = info[x];
        if (!o && !s) {
            ok[x] = 1;
            for (int v : adj[x]) {
                limit[v]--;
                if (!ok[v] && !limit[v])q1.push_back(v);
            }
            ans.push_back(x + 1);
        }
        else if (o && s && ch == -1) {
            ch = x;
            ok[x] = 1;
        }
        else {
            q2.push_back(x);
        }
    }
    if (ch != -1) {
        for (int v : adj[ch])if (!ok[v]) {
            limit[v]--;
            if (!ok[v] && !limit[v])q2.push_back(v);
        }
        ans.push_back(ch + 1);
        ch = -1;
        for (int i = 0;i < q2.size();++i) {
            int x = q2[i];
            if (ok[x])continue;
            auto [o, s] = info[x];
            if (o && !s) {
                ok[x] = 1;
                for (int v : adj[x])if (!ok[v]) {
                    limit[v]--;
                    if (!ok[v] && !limit[v])q2.push_back(v);
                }
                ans.push_back(x + 1);
            }
            else if (!o && s && ch == -1) {
                ch = x;
                ok[x] = 1;
            }
            else {
                q3.push_back(x);
            }
        }
        if (ch != -1) {
            for (int v : adj[ch])if (!ok[v]) {
                limit[v]--;
                if (!ok[v] && !limit[v])q3.push_back(v);
            }
            ans.push_back(ch + 1);
            for (int i = 0;i < q3.size();++i) {
                int x = q3[i];
                if (ok[x])continue;
                auto [o, s] = info[x];
                if (!o && !s) {
                    ok[x] = 1;
                    for (int v : adj[x])if (!ok[v]) {
                        limit[v]--;
                        if (!ok[v] && !limit[v])q3.push_back(v);
                    }
                    ans.push_back(x + 1);
                }
                else {
                    std::cout << -1;
                    return;
                }
            }
        }
        else if (q3.size()) {
            std::cout << -1;
            return;
        }
    }
    else if (q2.size()) {
        std::cout << -1;
        return;
    }
    for (int x : ans)std::cout << x << ' ';
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