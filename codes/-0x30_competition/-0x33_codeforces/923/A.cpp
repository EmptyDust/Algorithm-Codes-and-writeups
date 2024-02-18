#include <bits/stdc++.h>
#define int long long 
using namespace std;
constexpr int MAXN = 1e6 + 10;
int nums[MAXN], n;
using pt = pair<int, int>;

void solve() {
    int n;cin >> n;
    string s;cin >> s;
    int f = -1, l = 0;
    for (int i = 0;i < n;++i) {
        if (s[i] == 'B') {
            if (f == -1)f = i;
            l = i;
        }
    }
    cout << l - f + 1;
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