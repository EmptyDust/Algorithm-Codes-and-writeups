#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int MAXN = 1e3, mod = 998244353;
int mp[MAXN][MAXN];
int h, w, cnt = 0, c = 0;

//int dx[] = { 1,0,-1,0 }, dy[] = { 0,1,0,-1 };

void dfs(int x, int y) {
    if (x < 0 || y < 0 || x >= h || y >= w || mp[x][y] != 0)return;
    mp[x][y] = cnt;
    dfs(x - 1, y), dfs(x + 1, y), dfs(x, y - 1), dfs(x, y + 1);
}

int cal(int x, int y) {
    set<int> tmp;
    if (x > 0 && mp[x - 1][y] > 0) tmp.insert(mp[x - 1][y]);
    if (x < h - 1 && mp[x + 1][y] > 0) tmp.insert(mp[x + 1][y]);
    if (y > 0 && mp[x][y - 1] > 0) tmp.insert(mp[x][y - 1]);
    if (y < w - 1 && mp[x][y + 1] > 0) tmp.insert(mp[x][y + 1]);
    return (int)tmp.size() - 1;
}

void exGcd(int a, int b, int& x, int& y) {
    if (!b) { x = 1, y = 0; }
    else exGcd(b, a % b, y, x), y -= a / b * x;
}

int inv(int x) {
    int ret, y;
    exGcd(x, mod, ret, y);
    return (ret % mod + mod) % mod;
}

signed main() {
    ios::sync_with_stdio(false);
    cin >> h >> w;
    char tmp;
    for (int i = 0;i < h;++i) {
        for (int j = 0;j < w;++j) {
            cin >> tmp;
            if (tmp == '.')
                mp[i][j] = -1, c++;
            if (tmp == '#')
                mp[i][j] = 0;
        }
    }
    for (int i = 0;i < h;++i)
        for (int j = 0;j < w;++j)
            if (mp[i][j] == 0)++cnt, dfs(i, j);
    /*for (int i = 0;i < h;++i) {
        for (int j = 0;j < w;++j)
            cout << mp[i][j] << ' ';
        cout << endl;
    }*/
    int sum = 0;
    for (int i = 0;i < h;++i)
        for (int j = 0;j < w;++j)
            if (mp[i][j] == -1)
                sum = (sum + cnt - cal(i, j)) % mod;
    //cout << sum << endl;
    cout << (sum * inv(c)) % mod;
    return 0;
}