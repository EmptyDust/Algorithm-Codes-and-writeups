#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int MAXN = 6e6, mod = 1e9 + 7;
int nums[MAXN], v[MAXN];

void solve() {
    int n;cin >> n;
    if (n == 1) {
        cout << 1;
        return;
    }
    int g = n - 3;
    for (int i = 0;i <= g;i += 2) {
        cout << 1;
        for (int t = 0;t < i / 2;++t)cout << 0;
        cout << 6;
        for (int t = 0;t < i / 2;++t)cout << 0;
        cout << 9;
        for (int t = 0;t < g - i;++t)cout << 0;
        cout << '\n';
        cout << 9;
        for (int t = 0;t < i / 2;++t)cout << 0;
        cout << 6;
        for (int t = 0;t < i / 2;++t)cout << 0;
        cout << 1;
        for (int t = 0;t < g - i;++t)cout << 0;
        cout << '\n';
    }
    cout << 196;
    for (int t = 0;t < g;++t)cout << 0;

}

signed main() {
    ios::sync_with_stdio(false);
    int t;cin >> t;
    while (t--)
    {
        solve();
        cout << '\n';
    }
    return 0;
}