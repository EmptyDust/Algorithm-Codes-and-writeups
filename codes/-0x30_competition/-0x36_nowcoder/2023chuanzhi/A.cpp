#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    string s;cin >> s;
    string ans1, ans2;
    if (s.length() % 3 != 0) {
        cout << -1;
        return 0;
    }
    for (int i = 0;i < s.length(); ++i) {
        if (i < s.length() / 3 * 2)
            ans1 += s[i];
        else
            ans2 += s[i];
    }
    cout << ans1 << ' ' << ans2;
    return 0;
}