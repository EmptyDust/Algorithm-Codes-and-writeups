#include <bits/stdc++.h>
#define int long long 
using namespace std;

void solve() {
    int n;cin >> n;
    string s;cin >> s;
    cout << s[0];
    for (int i = 1;i < n - 1;++i) {
        if (s[i + 1] == 'a' || s[i + 1] == 'e') {
            cout << '.';
        }
        cout << s[i];
    }
    cout << s[n - 1];
}

signed main() {
    ios::sync_with_stdio(false);
    int t;cin >> t;
    while (t--) {
        solve();
        cout << '\n';
    }
    return 0;
}