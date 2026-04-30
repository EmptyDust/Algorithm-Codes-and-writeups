#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int MAXN = 1e6 + 10;
int nums[MAXN], n;
using pt = pair<int, int>;

void solve() {
    cin >> n;
    string s;cin >> s;
    string rev = s;
    reverse(rev.begin(), rev.end());
    if (s > rev)s = rev, n--;
    if (n & 1) {
        rev = s;
        reverse(rev.begin(), rev.end());
        s += rev;
    }
    cout << s;
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