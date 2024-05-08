#include <bits/stdc++.h>
//#define int long long
#define x first
#define y second
using namespace std;
using pint = pair<pair<int, int>, int>;
int m;
int mp[500][500] = { 0 };

inline void paint(int x, int y, int num) {
    mp[x][y] = num;
    mp[x + 1][y] = num;
    mp[x][y + 1] = num;
    if (x > 0)
        mp[x - 1][y] = num;
    if (y > 0)
        mp[x][y - 1] = num;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> m;
    vector<vector<int>> vct(m, vector<int>(3));
    for (int i = 0; i < m; i++) {
        cin >> vct[i][1] >> vct[i][2] >> vct[i][0];
        paint(vct[i][1], vct[i][2], 1);
    }
    sort(vct.begin(), vct.end(), [&](vector<int>& a, vector<int>& b) {return a[0] < b[0];});
    queue<pint> q;
    q.push({ {0,0},0 });
    int j = 0;

    while (!q.empty()) {
        pint& cut = q.front();
        if (mp[cut.first.x][cut.first.y] == 0) {
            cout << cut.second;
            return 0;
        }
        while (j < vct.size() && vct[j][0] <= cut.second) {
            paint(vct[j][1], vct[j][2], -1);
            ++j;
        }
        if (mp[cut.first.x][cut.first.y] == -1) {
            q.pop();
            continue;
        }
        q.push({ {cut.first.x + 1,cut.first.y},cut.second + 1 });
        if (cut.first.x > 0)
            q.push({ {cut.first.x - 1,cut.first.y},cut.second + 1 });
        q.push({ {cut.first.x,cut.first.y + 1},cut.second + 1 });
        if (cut.first.y > 0)
            q.push({ {cut.first.x,cut.first.y - 1},cut.second + 1 });

        mp[cut.first.x][cut.first.y] = -1;
        q.pop();
    }

    cout << -1;
    return 0;
}