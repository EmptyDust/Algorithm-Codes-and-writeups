#include <bits/stdc++.h>
//#define int long long 
using namespace std;
constexpr int MAXN = 1e3 + 10, mod = 1e9 + 7;
char mp[MAXN][MAXN];
using pt = pair<int, int>;
pt pts[MAXN];
#define op first
#define num second
int n, m, x, y;

void show() {
    for (int i = 0;i < n;++i) {
        for (int j = 0;j < m;++j)
            cout << mp[i][j];
        cout << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin >> n >> m >> x >> y;
    string s;
    for (int i = 0;i < n;++i) {
        cin >> s;
        for (int j = 0;j < m;++j)
            mp[i][j] = s[j];
    }
    int p, q;cin >> p >> q;
    for (int i = 0;i < q;++i)cin >> pts[i].op >> pts[i].num;
    for (int i = 0;i < p;++i) {
        for (int j = 0;j < q;++j) {
            int op = pts[j].op, z = pts[j].num - 1;
            if (op == 1) {
                auto tmp = mp[z][m - 1];
                for (int k = m - 1;k;--k)
                    mp[z][k] = mp[z][k - 1];
                mp[z][0] = tmp;
            }
            if (op == 2) {
                auto tmp = mp[n - 1][z];
                for (int k = n - 1;k;--k)
                    mp[k][z] = mp[k - 1][z];
                mp[0][z] = tmp;
            }
        }
    }
    cout << mp[x - 1][y - 1];
    return 0;
}