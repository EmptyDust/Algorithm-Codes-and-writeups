#include <bits/stdc++.h>
#define int long long 
using namespace std;
constexpr int MAXN = 1e6 + 10;
int nums[MAXN], n;
using pt = pair<int, int>;
#define l first
#define r second

void solve() {
    int n, m;cin >> n >> m;
    vector<int> cnts(n + 2, 0), f(n + 2, 0), minl(n + 2, 0);
    vector<pt> pts(m);
    int l, r;
    for (int i = 0;i < m;++i) {
        cin >> l >> r;
        cnts[l]++, cnts[r + 1]--;
        pts[i].l = l, pts[i].r = r;
    }
    for (int i = 1;i <= n;++i)cnts[i] += cnts[i - 1];
    sort(pts.begin(), pts.end(), [&](pt a, pt b) {return a.r > b.r;});
    for (int i = n, j = 0, l = n + 1;~i;--i) {
        if (i < l)l = n + 1;
        while (j < m && pts[j].r >= i) {
            l = min(l, pts[j].l);
            j++;
        }
        minl[i] = l;
    }
    for (int i = 1;i <= n;++i)
        f[i] = max(f[i - 1], f[minl[i] - 1] + cnts[i]);
    cout << f[n];
}

signed main() {
    ios::sync_with_stdio(false);
    int t;cin >> t;
    while (t--) {
        solve();
        cout << '\n';
    }
    return 0;
}