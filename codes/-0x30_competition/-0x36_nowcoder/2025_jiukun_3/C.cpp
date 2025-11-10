#include <bits/stdc++.h>

#define int long long
using namespace std;

using ll = long long;

const int N = 10000000;
const int mod = 998244353;

int ksm(int a, int b)
{
    ll ans = 1;
    while (b) {
        if (b & 1)
            ans = ans * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}

int getinv(int x)
{
    return ksm(x, mod - 2);
}

ll fac[N + 10], inv[N + 10];

void pre()
{
    fac[0] = inv[0] = 1;
    for (int i = 1; i <= N; i++) {
        fac[i] = fac[i - 1] * i % mod;
    }
    inv[N] = getinv(fac[N]);
    for (int i = N - 1; i; i--) {
        inv[i] = inv[i + 1] * (i + 1) % mod;
    }
}

ll C(ll n, ll m)
{
    if (n < m)
        return 0;
    return fac[n] * inv[m] % mod * inv[n - m] % mod;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> f(n + 1, 0);
    f[1] = 1;
    f[0] = 1;
    ll add = 2;
    if (m == 1) add = 1;
    for (int i = 2; i <= n; i++) {
        // ll res = 0;
        // for (int j = max(0ll, i - m); j < i; j++) {
        //     res += inv[j] % mod * f[j] % mod;
        //     res %= mod;
        //     // cout << "! " << i - 1 << " " << j - 1 << " " << C(i - 1, j - 1) << " " << f[j - 1] << endl;
        // }
        f[i] = (f[i] + add * fac[i - 1] % mod) % mod;
        add += inv[i] * f[i] % mod;
        add %= mod;
        if (i - m >= 0) {
            add -= inv[i - m] % mod * f[i - m] % mod;
            add = (add % mod + mod) % mod;
        }
        // cout << i << " " << f[i] << endl;
    }

    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += C(n - 1, i - 1) * f[i - 1] % mod * f[n - i] % mod;
        ans = ans % mod;
    }
    cout << ans << '\n';
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    pre();
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}