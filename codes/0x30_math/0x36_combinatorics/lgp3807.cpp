#include <bits/stdc++.h>
#define int long long
using namespace std;

int zh(int a, int b, int mod) {
    if (a < b)return 0;
    if (b > a / 2)b = a - b;
    int tmp = b;
    int ans = 1;
    for (int i = a;i > a - b;--i) {
        int t = i;
        while (tmp > 1 && t % tmp == 0) { t /= tmp;tmp--; }
        ans = (ans * t) % mod;
        cout << t << endl;
    }
    return ans % mod;
}

signed main() {
    ios::sync_with_stdio(false);
    int t;cin >> t;
    while (t--) {
        int n, m, p;
        cin >> n >> m >> p;
        cout << zh(n + m, n, p);
        cout << '\n';
    }
}