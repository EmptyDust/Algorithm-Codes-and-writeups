#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int MAXN = 1e6;
int cnts[MAXN];

void solve() {
    int n;cin >> n;
    int a, b;
    for (int i = 0;i < n;++i)cnts[i] = 0;

    for (int i = 0;i < n - 1;++i) {
        cin >> a >> b;
        a--, b--;
        cnts[a]++, cnts[b]++;
    }
    int cnt = 0;
    for (int i = 0;i < n;++i)if (cnts[i] == 1)cnt++;
    cout << (cnt + 1) / 2;
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