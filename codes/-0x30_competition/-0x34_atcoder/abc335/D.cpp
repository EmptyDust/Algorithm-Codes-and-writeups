#include<bits/stdc++.h>
#define int long long 
using namespace std;
#define x first
#define y second
constexpr int MAXN = 6e6;
using pt = pair<int, int>;

signed main() {
    ios::sync_with_stdio(false);
    int n;cin >> n;
    vector<vector<int>> mp(n, vector<int>(n, 0));
    pt dir[4] = { {1,0},{0,1},{-1,0},{0,-1} };
    pt cut = { 0,0 };
    int f = 0;
    for (int i = 1;i <= n * n;++i) {
        mp[cut.x][cut.y] = i;
        pt tmp = { cut.x + dir[f].x,cut.y + dir[f].y };
        if (tmp.x >= n || tmp.y >= n || tmp.x < 0 || tmp.y < 0 || mp[tmp.x][tmp.y] != 0) {
            f = (f + 1) % 4;
            tmp = { cut.x + dir[f].x,cut.y + dir[f].y };
        }
        cut = tmp;
    }
    for (int i = 0;i < n;++i) {
        for (int j = 0;j < n;++j) {
            if (mp[j][i] == n * n)cout << 'T';
            else cout << mp[j][i];
            cout << ' ';
        }
        cout << '\n';
    }
    return 0;
}