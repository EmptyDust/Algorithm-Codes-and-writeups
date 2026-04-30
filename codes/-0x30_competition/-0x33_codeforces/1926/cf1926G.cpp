#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int MAXN = 1e6 + 10;
int nums[MAXN], n;
using pt = pair<int, int>;
vector<int> adj[MAXN];

int ans;
void dfs(int x, int par) {
    int a = 0, b = 0;
    for (int nxt : adj[x])if (nxt != par) {
        dfs(nxt, x);
        if (nums[nxt] == 1)a++;
        if (nums[nxt] == 0)b++;
    }
    if (!a && !b) return;
    if (nums[x] == -1) {
        ans += min(a, b);
        if (a != b)
            nums[x] = a > b;
    }
    else ans += nums[x] ? b : a;
}

void solve() {
    int n;cin >> n;
    for (int i = 0;i < n;++i) {
        adj[i].clear();
    }
    int v;
    for (int i = 1;i < n;++i) {
        cin >> v;v--;int u = i;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    string s;cin >> s;
    for (int i = 0;i < n;++i) {
        if (s[i] == 'P')nums[i] = 1;
        if (s[i] == 'S')nums[i] = 0;
        if (s[i] == 'C')nums[i] = -1;
    }
    ans = 0;
    dfs(0, -1);
    cout << ans;
}

signed main() {
    ios::sync_with_stdio(false);
    int t;cin >> t;
    while (t--) {
        solve();
        cout << '\n';
    }
    return 0;
}