#include <bits/stdc++.h>
//#define int long long
using namespace std;
const int MAXN = 222222;
int bc[MAXN];
int nxt[MAXN];
int color[MAXN];
int f[MAXN];
int n;
int cnt, ans;
string s;
int st[MAXN];

int get_root(int x) {
    return bc[x] = (bc[x] == x ? x : get_root(bc[x]));
}

void f_cir(int x) {
    if (color[x] == cnt)
        return;
    color[x] = cnt;
    bc[get_root(x)] = bc[get_root(nxt[x])];
    f_cir(nxt[x]);
}

void f_cir_dfs(int x) {
    if (color[x] > 0)
        return;
    if (color[x] == -1) {
        cnt++;
        st[cnt] = x;
        f_cir(nxt[x]);
        return;
    }
    color[x] = -1;
    f_cir_dfs(nxt[x]);
    if (color[x] == -1)
        color[x] = 0;
}

void dfs_side(int x, bool sch, int par) {
    if (color[x] > 0) {
        if (sch)
            s[x - 1] = (s[x - 1] == '0' ? '1' : '0');
        return;
    }
    bool res = (sch ^ (s[x - 1] == '1'));
    if (res) {
        f[x] = f[par] + 1;
        dfs_side(nxt[x], 1, x);
    }
    else
        dfs_side(nxt[x], 0, x);
}

void solve() {
    //init
    cnt = 0, ans = 0;
    for (int i = 0;i <= n;++i)f[i] = 0;
    for (int i = 0;i <= n;++i)color[i] = 0;
    //input
    cin >> n;//>> s;
    iota(bc, bc + n + 1, 0);
    for (int i = 1; i <= n; i++)
        cin >> nxt[i];
    //判断环
    for (int i = 1; i <= n; i++)
        f_cir_dfs(i);


    cout << ans << '\n';
    //test
    for (int i = 1;i <= n;++i)cout << bc[i] << ' ';
    cout << endl;
    for (int i = 1;i <= n;++i)cout << color[i] << ' ';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t;cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}