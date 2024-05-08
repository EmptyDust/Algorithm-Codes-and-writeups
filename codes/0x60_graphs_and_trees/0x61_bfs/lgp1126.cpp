#include <bits/stdc++.h>
//#define int long long
using namespace std;
#define x first
#define y second
using pt = pair<int, int>;
using pint = pair<pt, pt>;
queue<pint> q;
int n, m;
int mp[100][100] = { 0 };
int visi[100][100][5] = { 0 };
/*
1:E
2:S
3:W
4:N
Ri:+1;
Le:-1;
*/
bool check(pt pos, int dirc) {
    int& x = pos.x, & y = pos.y;
    if (y >= m || x >= n || x == 0 || y == 0 || visi[x][y][dirc] != 0)
        return false;
    if (mp[x - 1][y] != 0 || mp[x - 1][y - 1] != 0 || mp[x][y - 1] != 0 || mp[x][y] != 0)
        return false;
    return true;
}

inline int cdirc(char ch) {
    if (ch == 'E')
        return 1;
    if (ch == 'S')
        return 2;
    if (ch == 'W')
        return 3;
    if (ch == 'N')
        return 4;
    return -1;
}

inline void psh(pt pos, int dir, int t) {
    if (dir == 2) {
        if (check({ pos.x + 1,pos.y }, dir)) {
            if (check({ pos.x + 2,pos.y }, dir)) {
                if (check({ pos.x + 3,pos.y }, dir))
                    q.push({ {pos.x + 3,pos.y},{t + 1,dir} });
                q.push({ {pos.x + 2,pos.y},{t + 1,dir} });
            }
            q.push({ {pos.x + 1,pos.y},{t + 1,dir} });
        }
        q.push({ pos,{t + 1,1} });
        q.push({ pos,{t + 1,3} });
    }
    if (dir == 4) {
        if (check({ pos.x - 1,pos.y }, dir)) {
            if (check({ pos.x - 2,pos.y }, dir)) {
                if (check({ pos.x - 3,pos.y }, dir))
                    q.push({ {pos.x - 3,pos.y},{t + 1,dir} });
                q.push({ {pos.x - 2,pos.y},{t + 1,dir} });
            }
            q.push({ {pos.x - 1,pos.y},{t + 1,dir} });
        }
        q.push({ pos,{t + 1,1} });
        q.push({ pos,{t + 1,3} });
    }
    if (dir == 1) {
        if (check({ pos.x,pos.y + 1 }, dir)) {
            if (check({ pos.x,pos.y + 2 }, dir)) {
                if (check({ pos.x,pos.y + 3 }, dir))
                    q.push({ {pos.x,pos.y + 3},{t + 1,dir} });
                q.push({ {pos.x,pos.y + 2},{t + 1,dir} });
            }
            q.push({ {pos.x,pos.y + 1},{t + 1,dir} });
        }
        q.push({ pos,{t + 1,2} });
        q.push({ pos,{t + 1,4} });
    }
    if (dir == 3) {
        if (check({ pos.x,pos.y - 1 }, dir)) {
            if (check({ pos.x,pos.y - 2 }, dir)) {
                if (check({ pos.x,pos.y - 3 }, dir))
                    q.push({ {pos.x,pos.y - 3},{t + 1,dir} });
                q.push({ {pos.x,pos.y - 2},{t + 1,dir} });
            }
            q.push({ {pos.x,pos.y - 1},{t + 1,dir} });
        }
        q.push({ pos,{t + 1,2} });
        q.push({ pos,{t + 1,4} });
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> mp[i][j];
    pt st, end;
    char dirc;
    cin >> st.x >> st.y >> end.x >> end.y >> dirc;
    if (!check(end, 0)) {
        cout << -1;
        return 0;
    }
    q.push({ st,{0,cdirc(dirc) } });
    while (!q.empty()) {
        pint& ct = q.front();
        pt& cutp = ct.first;
        pt& cut = ct.second;
        if (!check(cutp, cut.second)) {
            q.pop();
            continue;
        }

        if (cutp == end) {
            cout << cut.first;
            return 0;
        }
        psh(cutp, cut.second, cut.first);
        visi[cutp.x][cutp.y][cut.second] = 1;
        q.pop();
    }
    cout << -1;
    return 0;
}