#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int MAXN = 3;
int nums[MAXN], n;
using pt = pair<int, int>;
vector<int> adj[MAXN];

bool solve() {
    vector<vector<int>> mp(3, vector<int>(3, -1));
    int n;cin >> n;
    int u, v;
    while (n--) {
        cin >> u >> v >> o;
        int& cur = mp[u][v];
        if (~cur && cur != o)
            return false;
        if (o && mp[v][u])return false;
        cur = o;
        for (int k = 0;k < 3;++k)if (mp[v][k] == o) {

        }
    }
    for (int i = 0;i < 3;++i) {
        for (int j = 0;j < 3;++j) {
            if (mp[i][j] != 1)continue;
            for (int k = 0;k < 3;++k)if (mp[j][k] == 1) {
                int& cur = mp[i][k];
                if (~cur && cur != 1)
                    return false;
                cur = 1;
            }
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    int t;cin >> t;
    while (t--) {
        cout << solve() ? "Yes" : ":No";
        cout << '\n';
    }
    return 0;
}