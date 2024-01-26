#include <bits/stdc++.h>
#define int long long
using namespace std;
#define l first
#define r second
constexpr int MAXN = 1e6;
int bc[MAXN];

using pt = pair<int, int>;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n, m, x;cin >> n >> m >> x;
    vector<pt> pts(m);
    for (int i = 0;i < m;++i)cin >> pts[i].l >> pts[i].r;
    sort(pts.begin(), pts.end(), [&](pt a, pt b) {
        if (a.l == b.l)return a.r < b.r;
        return a.l < b.l;
        });
    iota(bc, bc + m, 0);
    int pre, cut = -1;
    for (int i = 0, l = -1, r = -1;i < m;++i) {
        pt& cur = pts[i];
        if (r < cur.l)l = cur.l, r = cur.r, cut = i;
        else bc[i] = cut, r = max(r, cur.r);
        if (l <= x && x <= r)pre = cut;
    }
    set<int> ans;
    for (int i = 0;i < m;++i)if (bc[i] == pre) {
        pt& cur = pts[i];
        if (cur.l <= x && x <= cur.r)ans.insert(cur.l), ans.insert(cur.r);
        if (cur.l > x)ans.insert(cur.r);
        if (cur.r < x)ans.insert(cur.l);
    }
    for (auto it = ans.begin();it != ans.end();++it)if (*it != x)cout << *it << ' ';
    return 0;
}