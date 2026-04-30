#include <bits/stdc++.h>
#define int long long 
using namespace std;

void solve() {
    int n;cin >> n;
    int sum = 0;
    for (int i = 0;i < n;++i) {
        int tmp;cin >> tmp;
        sum += tmp;
    }
    cout << (sqrt(sum) == (int)sqrt(sum) ? "Yes" : "No");
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