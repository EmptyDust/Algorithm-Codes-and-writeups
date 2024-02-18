#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 2e6 + 5;
const ll mod = 998244353;

vector<int> e[maxn];
ll dp[maxn][2];

void dfs(ll now, ll lst) {
    dp[now][0] = 1;
    dp[now][1] = 0;
    for (auto nxt : e[now]) {
        if (nxt == lst) continue;
        dfs(nxt, now);
        dp[now][0] = dp[nxt][0] * dp[now][0] % mod;
        dp[now][1] = (dp[nxt][0] - 1 + dp[nxt][1] + dp[now][1]) % mod;
    }
    dp[now][0]++;
}

void solve() {
    ll n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        e[i].clear();
    int u, v;
    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1, 0);
    cout << (dp[1][0] + dp[1][1]) % mod << endl;
}

int main() {
    ios::sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--) solve();
}