#include <bits/stdc++.h>
#define int long long 
using namespace std;
constexpr int MAXN = 1e6;
int nums[MAXN], k[MAXN];
using pt = pair<int, int>;

int solve() {
    int h, w, xa, ya, xb, yb;
    cin >> h >> w >> xa >> ya >> xb >> yb;
    if (xa >= xb)return -1;
    bool winner = (xb - xa) & 1;
    if (ya == yb)return winner;
    int len = (xb - xa + winner) >> 1;
    int la, ra, lb, rb;
    la = max((int)1, ya - len);
    ra = min(w, ya + len);
    len -= winner;
    lb = max((int)1, yb - len);
    rb = min(w, yb + len);
    bool f = winner ? (la <= lb && rb <= ra) : (lb <= la && ra <= rb);
    return (f ? winner : -1);
}

signed main() {
    ios::sync_with_stdio(false);
    int t;cin >> t;
    while (t--) {
        int res = solve();
        if (res == 1)cout << "Alice";
        if (res == 0)cout << "Bob";
        if (res == -1)cout << "Draw";
        cout << '\n';
    }
    return 0;
}