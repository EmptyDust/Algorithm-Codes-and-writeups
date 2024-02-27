#include <bits/stdc++.h>
#define int long long 
using namespace std;
constexpr int MAXN = 70;
int mp[MAXN][MAXN], dp[MAXN][MAXN][MAXN][MAXN];
using pt = pair<int, int>;
using a5 = array<int, 5>;
int n;

bool vaild(int x, int y) { return 0 <= x && x < n && 0 <= y && y < n && mp[x][y]; }

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    memset(dp, -1, sizeof dp);
    cin >> n;
    int p[2][2], pi = 0;
    string s;
    for (int i = 0;i < n;++i) {
        cin >> s;
        for (int j = 0;j < n;++j) {
            mp[i][j] = s[j] != '#';
            if (s[j] == 'P') {
                p[pi][0] = i;
                p[pi][1] = j;
                pi++;
            }
        }
    }
    queue<a5> q;
    q.push({ p[0][0],p[0][1],p[1][0],p[1][1],0 });
    int ans = -1;
    while (!q.empty()) {
        a5 cur = q.front();
        q.pop();
        int& res = dp[cur[0]][cur[1]][cur[2]][cur[3]];
        if (cur[0] == cur[2] && cur[1] == cur[3]) {
            ans = cur[4];
            break;
        }
        if (~res)continue;
        res = cur[4];
        q.push({
            vaild(cur[0] + 1, cur[1]) ? cur[0] + 1 : cur[0],cur[1],
            vaild(cur[2] + 1, cur[3]) ? cur[2] + 1 : cur[2],cur[3],
            res + 1 });
        q.push({
            vaild(cur[0] - 1,cur[1]) ? cur[0] - 1 : cur[0],cur[1],
            vaild(cur[2] - 1,cur[3]) ? cur[2] - 1 : cur[2],cur[3],
            res + 1 });
        q.push({
            cur[0],vaild(cur[0],cur[1] + 1) ? cur[1] + 1 : cur[1],
            cur[2],vaild(cur[2],cur[3] + 1) ? cur[3] + 1 : cur[3],
            res + 1 });
        q.push({
            cur[0],vaild(cur[0],cur[1] - 1) ? cur[1] - 1 : cur[1],
            cur[2],vaild(cur[2],cur[3] - 1) ? cur[3] - 1 : cur[3],
            res + 1 });
    }
    cout << ans;
    return 0;
}