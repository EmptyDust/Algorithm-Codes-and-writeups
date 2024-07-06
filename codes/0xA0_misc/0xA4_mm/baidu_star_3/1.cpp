#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll inf = 0x3f3f3f3f3f3f3f3fLL;
const int infi = 0x3f3f3f3f;

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    ll l, r, c;
    cin >> l >> r >> c;
    auto calc = [&](ll mid, ll a, ll b) -> ll {
        if (b > mid) return 0;
        mid -= b;
        mid++;
        return (mid + a - 1) / a;
        };
    ll left = l, right = r - 1, ans = -1;
    while (left <= right) {
        ll mid = left + (right - left) / 2;
        ll cnt = 0;
        for (int i = 1; i <= n && cnt < c; i++) {
            cnt += calc(mid, a[i], b[i]) - calc(l - 1, a[i], b[i]);
        }
        if (cnt >= c) {
            ans = mid;
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    cout << ans << endl;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t = 1;
    //cin >> t;

    while (t--) {
        solve();
    }
}