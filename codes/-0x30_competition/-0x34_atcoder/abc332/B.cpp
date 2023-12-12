#include <bits/stdc++.h>
#define int long long 
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int k, g, m;
    cin >> k >> g >> m;
    int cg = 0, cm = 0;
    while (k--) {
        if (cg == g)
            cg = 0;
        else if (cm == 0)
            cm = m;
        else {
            cg += cm;
            cm = 0;
            if (cg > g) {
                cm = cg - g;
                cg = g;
            }
        }
    }
    cout << cg << ' ' << cm;
    return 0;
}