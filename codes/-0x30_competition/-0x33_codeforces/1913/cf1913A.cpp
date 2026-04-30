#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int MAXN = 1e6;
constexpr int mod = 1e9 + 7;
using pt = pair<int, int>;

void solve() {
    string s;cin >> s;
    if (s[0] == '0') {
        cout << -1;
        return;
    }
    int a = s[0] - '0', b = 0;
    int i;
    for (i = 1;i < s.length();++i) {
        if (s[i] == '0')
            a *= 10;
        else
            break;
    }
    while (i < s.length()) {
        b = b * 10 + s[i] - '0';
        ++i;
    }
    if (a < b)
        cout << a << ' ' << b;
    else
        cout << -1;
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