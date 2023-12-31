#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int MAXN = 6e6, mod = 1e9 + 7;
int nums[MAXN], v[MAXN];

void solve() {
    int a, b;cin >> a >> b;
    if (a < b)swap(a, b);
    if (b == 1) {
        cout << a * a;
        return;
    }
    int gcd = __gcd(a, b);
    int res = a / gcd * b;
    if (res == max(a, b))res *= a / b;
    cout << res;
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