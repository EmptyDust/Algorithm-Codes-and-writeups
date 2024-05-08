//lgp1049 day0C by Empty_Dust
#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    int v, n, w;cin >> v >> n;
    vector<bool> bag(v + 1, false);
    bag[0] = true;
    while (n--) {
        cin >> w;
        for (int i = v;i >= w;--i)if (bag[i - w])bag[i] = true;
    }
    int ans;
    for (int i = v;i >= 0;--i)if (bag[i]) { ans = v - i; break; }
    cout << ans;
    return 0;
}