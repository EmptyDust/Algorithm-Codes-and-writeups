#include <bits/stdc++.h>
#define int long long 
using namespace std;
constexpr int MAXN = 1e6;
int nums[MAXN];
using pt = pair<int, int>;

void solve() {
    int n;cin >> n;
    string a, b, c;
    cin >> a >> b >> c;
    bool f = false;
    for (int i = 0;i < n;++i) {
        if (c[i] != b[i] && c[i] != a[i])f = true;
    }
    cout << (f ? "YES" : "NO");

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t;cin >> t;
    while (t--) {
        solve();
        cout << '\n';
    }
    return 0;
}