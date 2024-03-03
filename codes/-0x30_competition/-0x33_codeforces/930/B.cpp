#include <bits/stdc++.h>
//#define int long long
using namespace std;
constexpr int MAXN = 2e5 + 10;
int n;
bool mp[MAXN][2], res[MAXN];
using pt = pair<int, int>;

void init() {
    string s, t;cin >> s >> t;
    for (int i = 0;i < n;++i)mp[i][0] = s[i] == '1';
    for (int i = 0;i < n;++i)mp[i][1] = t[i] == '1';
}

void solve() {
    cin >> n;
    init();
    int ani = 0;
    int ans = 1, k = 1, x = 0;
    for (;x < n - 1;++x) {
        res[ani++] = mp[x][0];
        if (mp[x + 1][0] && !mp[x][1])
            break;
        if (mp[x + 1][0] == mp[x][1])
            k++;
        else
            k = 1;
    }
    if (x == n - 1)res[ani++] = mp[n - 1][0];
    for (;x < n;++x)res[ani++] = mp[x][1];
    for (int i = 0;i < ani;++i)cout << res[i];
    cout << '\n' << k;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t;cin >> t;
    while (t--) {
        solve();
        cout << '\n';
    }
    return 0;
}