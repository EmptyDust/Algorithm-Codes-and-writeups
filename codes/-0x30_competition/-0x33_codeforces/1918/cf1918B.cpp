#include <bits/stdc++.h>
#define int long long 
using namespace std;
constexpr int MAXN = 1e6 + 10;
int n;
using pt = pair<int, int>;
pt pts[MAXN];

void solve() {
    int n;cin >> n;
    for (int i = 0;i < n;++i)cin >> pts[i].first;
    for (int i = 0;i < n;++i)cin >> pts[i].second;
    sort(pts, pts + n, [&](pt a, pt b) {return a.first < b.first;});
    for (int i = 0;i < n;++i)cout << pts[i].first << ' ';cout << '\n';
    for (int i = 0;i < n;++i)cout << pts[i].second << ' ';
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