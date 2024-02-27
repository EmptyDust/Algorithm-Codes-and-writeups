#include <bits/stdc++.h>
#define int long long 
using namespace std;
constexpr int MAXN = 1e6 + 10, mod = 1e9 + 7;
int p[MAXN], ans[MAXN], color[MAXN];
vector<int> adj[MAXN];
vector<int> rps;

vector<int> children;
void dfs(int x) {
    children.push_back(x);
    for (int nxt : adj[x])if (!color[nxt])
        dfs(nxt);
}

signed main() {
    ios::sync_with_stdio(false);
    int n;cin >> n;
    for (int i = 1;i <= n;++i)ans[i] = 1;
    string s;cin >> s;
    for (int i = 2;i <= n;++i) {
        cin >> p[i];
        adj[p[i]].push_back(i);
    }
    for (int i = 1;i <= n;++i) {
        color[i] = s[i - 1] == 'R';
        if (color[i])rps.push_back(i);
    }
    for (int rp : rps) {
        children.clear();
        dfs(rp);
        int s = children.size();
        if (s == 1) {
            cout << -1;
            return 0;
        }
        while (s > 3) {
            s--;
            ans[children[s]] = 1;
            s--;
            ans[children[s]] = 2;
        }
        if (s == 3) {
            for (int i = 0;i < s;++i)
                ans[children[i]] = 1;
        }
        else {
            s--;
            ans[children[s]] = 1;
            s--;
            ans[children[s]] = 2;
        }
    }
    string a;
    for (int i = 1;i <= n;++i)
        a += (char)(ans[i] + '0');
    cout << a;
    return 0;
}