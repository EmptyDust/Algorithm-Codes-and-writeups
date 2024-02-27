#include <bits/stdc++.h>
//#define int long long 
using namespace std;
constexpr int MAXN = 3e3 + 10, mod = 1e9 + 7;
int mp[MAXN][MAXN], dp1[MAXN][MAXN], dp2[MAXN][MAXN], dp[MAXN][MAXN], cal[MAXN][MAXN];
int n, m;

int solve(int x, int l, int len) {
    int cnt = 0;
    for (int i = l;i < l + len;i += 2)
        for (int j = i + 2;j < l + len;j += 2)
            if (dp2[x][i] >= (j - i) / 2 && dp1[x][j] >= (j - i) / 2)
                cnt++;
    //cout << l << ' ' << len << ' ' << cnt << endl;
    return cnt;
}

void init_cal1(int x, int y) {
    int cnt = -1;
    while (x < n && y < m) {
        if (!mp[x][y])cnt = -1;
        else dp1[x][y] = ++cnt;
        x++;y++;
    }
}

void init_cal2(int x, int y) {
    int cnt = -1;
    while (x < n && ~y) {
        if (!mp[x][y])cnt = -1;
        else dp2[x][y] = ++cnt;
        x++;y--;
    }
}

void init() {
    for (int j = 0;j < m;++j)init_cal1(0, j);
    for (int i = 1;i < n;++i)init_cal1(i, 0);
    for (int j = 0;j < m;++j)init_cal2(0, j);
    for (int i = 1;i < n;++i)init_cal2(i, m - 1);
}

signed main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    string s;
    for (int i = 0;i < n;++i) {
        cin >> s;
        for (int j = 0;j < m;++j)
            mp[i][j] = s[j] == '*';
    }
    init();
    int ans = 0;
    for (int i = 0;i < n;++i) {
        for (int j = 0;j < m;++j)if (mp[i][j]) {
            int len = 0, l = j;
            for (;j < m;++j) {
                if (mp[i][j])len++;
                else break;
            }
            if (len > 2)ans += solve(i, l, len);
            if (len > 3)ans += solve(i, l + 1, len - 1);
        }
    }
    cout << ans;
    return 0;
}