#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int mod = 1E9 + 7;

ll f(ll a, ll b) {
    return a * ll(1E9) + b;
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<ll> a(n), b(m);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    typedef array<ll, 3> array3;
    priority_queue<array3, vector<array3>, greater<array3>> q;
    unordered_map<ll, int>mp;

    q.push({ a[0] + b[0], 0, 0 });
    mp[f(0, 0)]++;

    ll res = 0;
    while (k--) {
        auto [val, x, y] = q.top();
        q.pop();

        res = (res + val % mod) % mod;

        if (x + 1 < n && !mp[f(x + 1, y)]) {
            q.push({ a[x + 1] + b[y], x + 1, y });
            mp[f(x + 1, y)]++;
        }
        if (y + 1 < m && !mp[f(x, y + 1)]) {
            q.push({ a[x] + b[y + 1], x, y + 1 });
            mp[f(x, y + 1)]++;
        }
    }
    cout << res << '\n';
}
int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}