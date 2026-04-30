#include <bits/stdc++.h>
#define int long long 
using namespace std;
constexpr int MAXN = 1e6 + 10;
int nums[MAXN], n;
using pt = pair<int, int>;

void solve() {
    int n;cin >> n;
    string s;cin >> s;
    int cnt = 0, ans = 0;
    for (char ch : s) {
        if (ch != '*')cnt = 0;
        if (ch == '@')
            ans++;
        if (ch == '*') {
            cnt++;
            if (cnt == 2)break;
        }
    }
    cout << ans;
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