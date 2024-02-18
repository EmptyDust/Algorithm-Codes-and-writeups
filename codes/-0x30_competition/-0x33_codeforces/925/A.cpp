#include <bits/stdc++.h>
#define int long long 
using namespace std;
constexpr int MAXN = 1e6 + 10;
int nums[MAXN], n;
using pt = pair<int, int>;

void solve() {
    int n;cin >> n;
    string s = "aaa";
    if (n > 28) {
        s[2] = 'z';
        if (n > 53) {
            s[1] = 'z';
            s[0] = 'a' + n - 52 - 1;
        }
        else
            s[1] = 'a' + n - 26 - 2;
    }
    else {
        s[2] = 'a' + n - 3;
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