#include <bits/stdc++.h>
#define int long long 
using namespace std;
constexpr int MAXN = 1e6;
int nums[MAXN];
using pt = pair<int, int>;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int h, w, n;cin >> h >> w >> n;
    int move[4][2] = { {-1,0}, {0,1}, {1,0}, {0,-1} };
    int op = 0;
    vector<vector<int>> mp(h, vector<int>(w, 0));
    for (int x = 0, y = 0, i = 0;i < n;++i) {
        if (mp[x][y]) {
            mp[x][y] = 0;
            op = (op + 3) % 4;
        }
        else {
            mp[x][y] = 1;
            op = (op + 1) % 4;
        }
        x += move[op][0];
        y += move[op][1];
        x = (x + h) % h;
        y = (y + w) % w;
    }
    for (int i = 0;i < h;++i) {
        for (int j = 0;j < w;++j) {
            cout << (mp[i][j] ? '#' : '.');
        }
        cout << '\n';
    }
    return 0;
}