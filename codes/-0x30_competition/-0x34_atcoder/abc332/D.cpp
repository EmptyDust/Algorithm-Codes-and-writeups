#include <bits/stdc++.h>
#define int long long 
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int m, n;
    cin >> m >> n;
    vector<vector<int>> a(m, vector<int>(n));
    vector<vector<int>> b(m, vector<int>(n));
    vector<int> lie(m, -1);
    vector<int> hang(n, -1);

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> b[i][j];

    for (int i = 0;i < m;++i) {
        bool f = false;
        vector<int> tmp2 = b[i];
        sort(tmp2.begin(), tmp2.end());
        for (int k = 0; k < m; k++)
        {
            vector<int> tmp1 = a[k];
            sort(tmp1.begin(), tmp1.end());

            if (tmp1 == tmp2 && lie[k] == -1) {
                lie[k] = i;
                f = true;
                break;
            }
        }
        if (!f) {
            cout << -1;
            return 0;
        }
    }

    int cnt = 0;
    for (int i = 0;i < m;++i)
        for (int j = 0;j < i;++j)
            if (lie[j] > lie[i])
                cnt++;

    vector<vector<int>> anew(m, vector<int>(n));
    for (int i = 0;i < m;++i)
        anew[i] = a[lie[i]];

    for (int i = 0;i < n;++i) {
        bool f = false;
        vector<int> tmp2;
        for (int j = 0; j < m; j++)
            tmp2.push_back(b[j][i]);

        for (int k = 0; k < n; k++)
        {
            vector<int> tmp1;
            for (int j = 0; j < m; j++)
                tmp1.push_back(anew[j][k]);

            if (tmp1 == tmp2 && hang[k] == -1) {
                hang[k] = i;
                f = true;
                break;
            }
        }
        if (!f) {
            cout << -1;
            return 0;
        }
    }

    for (int i = 0;i < n;++i)
        for (int j = 0;j < i;++j)
            if (hang[j] > hang[i])
                cnt++;

    cout << cnt;
    return 0;
}