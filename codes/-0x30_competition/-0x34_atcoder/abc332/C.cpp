#include <bits/stdc++.h>
//#define int long long 
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    int ans = 0, cnt = 0, cntt = 0;
    for (char ch : s) {
        if (ch == '0')
            cnt = 0, cntt = 0;
        if (ch == '1')
            cnt++;
        if (ch == '2')
            cntt++;
        ans = max(ans, cntt + max(0, cnt - m));
    }
    cout << ans;
    return 0;
}