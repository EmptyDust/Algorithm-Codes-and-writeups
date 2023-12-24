#include <bits/stdc++.h>
#define int long long
#define ll long long
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    int a, m, l, r;
    cin >> a >> m >> l >> r;
    int tmp = (l % m + m) % m;
    if (r - l < ((a % m - tmp) % m + m) % m)
        //cout << ans << endl;
        cout << 0;
    else cout << (r - l - ((a % m - tmp) % m + m) % m) / m + 1;
    return 0;
}