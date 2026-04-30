#include <bits/stdc++.h>
#define int long long 
using namespace std;
constexpr int MAXN = 1e6;
int nums[MAXN];
using pt = pair<int, int>;

void solve() {
    set<int> a, b;
    for (int i = 0;i < 4;++i) {
        int t, g;
        cin >> t >> g;
        a.insert(t);
        b.insert(g);
    }
    cout << abs(*a.begin() - *(--a.end())) * abs(*b.begin() - *(--b.end()));
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