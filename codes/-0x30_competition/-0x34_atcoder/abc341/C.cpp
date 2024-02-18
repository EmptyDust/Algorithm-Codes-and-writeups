#include <bits/stdc++.h>
#define int long long 
using namespace std;
constexpr int MAXN = 500 + 10;
int mp[MAXN][MAXN];
using pt = pair<int, int>;
string t, s;
int h, w, n;

bool vaild(int x, int y) {
    if (x < 0 || x >= h || y < 0 || y >= w)
        return false;
    return mp[x][y];
}

bool check(int x, int y) {
    for (char ch : t) {
        if (ch == 'U')x--;
        if (ch == 'D')x++;
        if (ch == 'L')y--;
        if (ch == 'R')y++;
        if (!vaild(x, y))return false;
    }
    return true;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> h >> w >> n;
    cin >> t;
    for (int i = 0;i < h;++i) {
        cin >> s;
        for (int j = 0;j < w;++j)
            mp[i][j] = (s[j] == '.');
    }
    int cnt = 0;
    for (int i = 0;i < h;++i)for (int j = 0;j < w;++j)if (vaild(i, j)) {
        cnt += check(i, j);
        //if (check(i, j))cout << i << j << endl;
    }
    cout << cnt;
    return 0;
}