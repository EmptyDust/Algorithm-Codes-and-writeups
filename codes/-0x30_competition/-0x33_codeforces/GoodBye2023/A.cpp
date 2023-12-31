#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int MAXN = 6e6, mod = 1e9 + 7;
int nums[MAXN], v[MAXN];

void solve() {
    int n, k;cin >> n >> k;
    for (int i = 0;i < n;++i)cin >> nums[i];
    int a = 2023;
    for (int i = 0;i < n;++i) {
        if (a % nums[i] != 0) {
            cout << "NO";
            return;
        }
        a /= nums[i];
    }
    cout << "YES" << '\n';
    cout << a << ' ';
    for (int i = 0;i < k - 1;++i)cout << 1 << ' ';
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