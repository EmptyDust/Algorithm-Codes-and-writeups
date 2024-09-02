#include <bits/stdc++.h>
//#define int long long 
using namespace std;
constexpr int MAXN = 2e3;
int n, m, u, v, w;

signed main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    vector<vector<int>> mp(n, vector<int>(n, 10000));
    for (int _ = 0; _ < m; _++)
    {
        cin >> u >> v >> w;
        u--, v--;
        mp[u][v] = w;
        mp[v][u] = w;
    }


    for (int i = 0; i < n; i++)
    {
        for (int ja = 0; ja < n; ja++)
        {
            if (mp[i][ja] == 10000)continue;
            for (int jb = ja + 1; jb < n; jb++)
            {
                if (mp[jb][i] == 10000)continue;
                if (mp[jb][i] + mp[i][ja] < mp[jb][ja])
                    mp[ja][jb] = mp[jb][ja] = mp[jb][i] + mp[i][ja];
            }
        }
    }

    for (int _ = 0; _ < n; _++) {
        for (int i = 0; i < n; i++) {
            if (i == _) { cout << 0 << ' ';continue; }
            cout << mp[_][i] << ' ';
        }
        cout << '\n';
    }

    return 0;
}