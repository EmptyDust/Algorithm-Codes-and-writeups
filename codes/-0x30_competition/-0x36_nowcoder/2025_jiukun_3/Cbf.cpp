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

    int ans = 0;
    vector<int> p(n + 1);
    iota(p.begin(), p.end(), 0);
    do {
        int flag = 1;
        for (int l = 1; l <= n; l++) {
            for (int r = l + 1; r <= n; r++) {
                int mnidx = l, mxidx = l;
                for (int k = l; k <= r; k++) {
                    if (p[mnidx] > p[k]) mnidx = k;
                    if (p[mxidx] < p[k]) mxidx = k;
                }
                if (abs(mxidx - mnidx) > m)flag = 0;
            }
        }
        ans += flag;
    } while (next_permutation(next(p.begin()), p.end()));

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