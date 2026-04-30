#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int MAXN = 1e6;
constexpr int mod = 1e9 + 7;
using pt = pair<int, int>;

void solve() {
    string s;cin >> s;
    int cnt0 = 0, cnt1 = 0;
    for (char ch : s) {
        if (ch == '0')
            cnt0++;
        else cnt1++;
    }
    int ans = 0;
    for (char ch : s) {
        if (ch == '0') {
            if (cnt1)cnt1--;
            else break;
        }
        else {
            if (cnt0)cnt0--;
            else break;
        }
        ans++;
    }
    cout << s.length() - ans;
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