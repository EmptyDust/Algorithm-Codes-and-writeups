#include <bits/stdc++.h>
#define int long long 
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n, s, k;
    cin >> n >> s >> k;
    int sum = 0;
    while (n--) {
        int tmp, q;
        cin >> tmp >> q;
        sum += tmp * q;
    }
    if (sum < s)
        sum += k;
    cout << sum;
    return 0;
}