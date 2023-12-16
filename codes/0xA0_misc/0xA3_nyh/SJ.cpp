#include<bits/stdc++.h>
#define int long long
using namespace std;
#define MAXN 1e9

int res(int m, int n) {
    if (n == 1)return m;
    int tmp = res(m, n / 2);
    if (tmp > MAXN || tmp * tmp > MAXN || tmp == -1)return -1;
    if (n & 1)return tmp * tmp * m;
    return tmp * tmp;
}

signed main() {
    ios::sync_with_stdio(false);
    int m, n;
    cin >> m >> n;
    if (m == 1 || m == 0) {
        cout << m;
        return 0;
    }
    if (n >= 31) {
        cout << -1;
        return 0;
    }
    int ans = res(m, n);
    if (ans > MAXN)ans = -1;
    cout << ans;

    return 0;
}