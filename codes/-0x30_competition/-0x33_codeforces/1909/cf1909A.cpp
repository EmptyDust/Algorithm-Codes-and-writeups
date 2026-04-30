#include <bits/stdc++.h>
#define int long long
#define ll long long
using namespace std;
constexpr int MAXN = 5e6 + 10;
int nums[MAXN];
bool ans[8];
int t, n;

void solve() {
    cin >> n;
    for (int i = 0;i < 8;++i)ans[i] = 0;
    int x, y;
    while (n--) {
        cin >> x >> y;
        if (x > 0 && y == 0) ans[0] = 1;
        if (x > 0 && y > 0) ans[1] = 1;
        if (x == 0 && y > 0) ans[2] = 1;
        if (x < 0 && y > 0) ans[3] = 1;
        if (x < 0 && y == 0) ans[4] = 1;
        if (x < 0 && y < 0) ans[5] = 1;
        if (x == 0 && y < 0) ans[6] = 1;
        if (x > 0 && y < 0) ans[7] = 1;
    }
    bool f = false;
    if (!ans[1] && !ans[2] && !ans[3] || !ans[3] && !ans[4] && !ans[5] || !ans[5] && !ans[6] && !ans[7] || !ans[7] && !ans[0] && !ans[1])f = true;
    cout << (f ? "YES" : "NO");
}

signed main() {
    ios::sync_with_stdio(false);
    cin >> t;
    while (t--) {
        solve();
        cout << '\n';
    }
    return 0;
}