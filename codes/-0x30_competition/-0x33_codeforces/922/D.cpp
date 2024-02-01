#include <bits/stdc++.h>
#define int long long 
using namespace std;
constexpr int MAXN = 1e6 + 10;
int sums[MAXN], a[MAXN], f[MAXN], q[MAXN], n;
using pt = pair<int, int>;

int l, r;
bool check(int lim) {
    f[0] = 0, q[1] = 0, l = r = 1;
    for (int i = 1;i <= n + 1;++i) {
        while (l < r && sums[i - 1] - sums[q[l]]>lim)l++;
        f[i] = f[q[l]] + a[i];
        while (l<r && f[q[r]]>f[i])r--;
        q[++r] = i;
    }
    return f[n + 1] <= lim;
}

void solve() {
    cin >> n;
    for (int i = 1;i <= n;++i) {
        cin >> a[i];
        sums[i] = sums[i - 1] + a[i];
    }
    a[n + 1] = 0, sums[n + 1] = sums[n];
    int l = 1, r = sums[n], mid;
    while (l < r) {
        mid = l + r >> 1;
        if (check(mid))r = mid;
        else l = mid + 1;
    }
    cout << r;
}

signed main() {
    ios::sync_with_stdio(false);
    signed t;cin >> t;
    while (t--) {
        solve();
        cout << '\n';
    }
    return 0;
}