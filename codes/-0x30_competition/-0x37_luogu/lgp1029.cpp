#include <bits/stdc++.h>
#define int long long 
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int x, y, n;
    cin >> x >> y;
    if (y % x != 0) {
        cout << 0;
        return 0;
    }
    n = y / x;
    int cnt = 0;
    for (int i = 2;i <= n;++i) {
        if (n % i == 0)
            cnt++;
        while (n % i == 0) {
            n /= i;
        }
    }
    cout << (int)pow(2, cnt);
    return 0;
}