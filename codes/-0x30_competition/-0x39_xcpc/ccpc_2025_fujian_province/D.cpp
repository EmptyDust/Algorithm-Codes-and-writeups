//
//   ____      _                           _          _    __     ____     ___    ____    _____ 
//  |  _ \    (_)   __ _   _ __     __ _  | |   ___  / |  / /_   |___ \   ( _ )  | ___|  |___  |
//  | | | |   | |  / _` | | '_ \   / _` | | |  / _ \ | | | '_ \    __) |  / _ \  |___ \     / / 
//  | |_| |   | | | (_| | | | | | | (_| | | | |  __/ | | | (_) |  / __/  | (_) |  ___) |   / /  
//  |____/   _/ |  \__,_| |_| |_|  \__, | |_|  \___| |_|  \___/  |_____|  \___/  |____/   /_/   
//          |__/                   |___/                                                        
//
//  [题目链接] ： 
//
//  [题目名称] ： 
//
//  [  做法  ] ： 
//
#include <bits/stdc++.h>
#define fir first
#define sec second
#define el '\n'
#define all(x) (x).begin(), (x).end()
#define FINISH cout << "FINISH" << endl;
#define debug(x) cout << #x << " :== " << x << endl;
#define debugv(x)\
    cout << #x << " :: ";\
    for (auto v : x) cout << v << " ";\
    cout << endl;

using namespace std;
typedef long long ll;
typedef pair<int, int> PII;

const int mod = 998244353;
const int inf32 = 0x3f3f3f3f;
const ll inf64 = 0x3f3f3f3f3f3f3f3f;

struct dsu {
    std::vector<int> d;
    dsu(int n) { d.resize(n); iota(d.begin(), d.end(), 0); }
    int get_root(int x) { return d[x] = (x == d[x] ? x : get_root(d[x])); };
    bool merge(int u, int v) {
        if (get_root(u) != get_root(v)) {
            d[get_root(u)] = get_root(v);
            return true;
        }
        else return false;
    }
};

void solve()
{
    int n;
    cin >> n;

    int a = (n + 2) & -(n + 2);
    int b = n + 2 - a;
    if (b == 0)a = b = (n + 2) / 2;

    vector<int> u(n * 2 + 3);
    vector<int> v(n * 2 + 3);
    vector<int> inp(n + 1, 0);
    vector<vector<PII>> edge(n + 1);
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        inp[x]++, inp[y]++;

        edge[x].push_back({ y, i * 2 });
        edge[y].push_back({ x, i * 2 + 1 });

        u[i * 2] = x, v[i * 2] = y;
        u[i * 2 + 1] = y, v[i * 2 + 1] = x;
    }

    vector<int> siz(n * 2 + 3, 0), dp(n * 2 + 3, 0);
    vector<int> vis(n * 2 + 3, 0);
    auto dfs = [&](auto& self, int x) -> void
        {
            // cout << x << " " << u[x] << " " << v[x] << endl;
            if (vis[x])
                return;
            vis[x] = 1;

            siz[x] = 1;
            int U = u[x], V = v[x];
            vector<int> e;
            for (auto [to, idx] : edge[V]) {
                if (idx == (x ^ 1))
                    continue;
                e.push_back(to);
                self(self, idx);
                siz[x] += siz[idx];
            }
            dp[x] = 0;
            // debugv(e);
            if (e.size() == 0)
                dp[x] = 1;

            else if (e.size() == 2) {
                if (dp[e[0]] == 1 && dp[e[1]] == 1 && siz[e[0]] == siz[e[1]]) {
                    dp[x] = 1;
                }
            }
        };

    auto check = [&](int idx) -> bool
        {
            auto tinp = inp;
            tinp[u[idx]]--;
            tinp[v[idx]]--;
            dsu d(n + 1);
            for (int u = 1;u <= n;++u) {
                for (auto [to, i] : edge[u])if (i != idx || i != (idx ^ 1)) {
                    d.merge(u, to);
                }
            }
            std::vector count(2, std::vector<int>(5));
            for (int u = 1;u <= n;++u) {
                int cnt = tinp[u];
                if (tinp[u] > 3) {
                    return false;
                }
                count[d.get_root(u) == d.get_root(1)][tinp[u]]++;
                count[d.get_root(u) == d.get_root(1)][4]++;
            }
            if (count[0][2] != 1 || count[1][2] != 1)return false;
            if (count[0][4] == a && count[1][4] == b || count[])
        };

    int cnt = 0;
    vector<int> inp2;
    for (int i = 1; i <= n; i++) {
        if (inp[i] == 4) {
            for (auto [to, idx] : edge[i]) {
                if (check(idx)) {
                    cout << idx / 2 << endl;
                    return;
                }
            }
        }
        else if (inp[i] == 2) {
            inp2.push_back(i);
        }
    }

    // debugv(inp2);
    for (auto st : inp2) {
        for (auto [to, idx] : edge[st]) {
            if (check(idx)) {
                cout << idx / 2 << endl;
                return;
            }
        }
    }

    FINISH
        for (int i = 2; i <= n * 2 - 1; i++) {
            if (vis[i] == 0) {
                // debug(i);
                dfs(dfs, i);
                // FINISH
            }
        }

    for (int i = 2; i <= n * 2 - 1; i++) {
        cout << dp[i] << " " << u[i] << " " << v[i] << endl;
    }
    // debugv(dp);
    for (int i = 1; i < n; i++) {
        if (dp[i * 2] && dp[i * 2 + 1]) {
            cout << i << el;
            return;
        }
    }
    // cout << "-1" << el;
    // cout  << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
        cout.flush();
    }
    return 0;
}

