#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int MAXN = 1e6 + 10;
int nums[MAXN], n;
using pt = pair<int, int>;

void solve() {
    int n;cin >> n;
    int m = 0;
    for (int i = 0;i < n;++i) {
        cout << '?' << ' ' << i << ' ' << i << ' ' << m << ' ' << m << endl;
        char c;cin >> c;
        if (c == '>')m = i;
    }
    vector<int> s;
    int sm = 0;
    for (int i = 0;i < n;++i) {
        cout << '?' << ' ' << i << ' ' << m << ' ' << sm << ' ' << m << endl;
        char c;cin >> c;
        if (c == '>') {
            s.clear();
            s.emplace_back(i);
            sm = i;
        }
        if (c == '=')s.emplace_back(i);
    }
    int ans = s[0];
    for (int x : s) {
        cout << '?' << ' ' << x << ' ' << x << ' ' << ans << ' ' << ans << endl;
        char c;cin >> c;
        if (c == '<')ans = x;
    }
    cout << '!' << ' ' << m << ' ' << ans;
}

signed main() {
    int t;cin >> t;
    while (t--) {
        solve();
        cout << endl;
    }
    return 0;
}