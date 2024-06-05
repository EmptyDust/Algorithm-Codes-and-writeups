#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define int long long
constexpr int N = 5e3, MAXN = 5e3 + 10, inf = 1e18, mod = 998244353;
using pt = pair<int, int>;
int f[2][2][MAXN];
int newf[2][2][MAXN];

signed main() {
    ios::sync_with_stdio(false);
    std::cin.tie(0), cout.tie(0);
    int n, k;
    cin >> n >> k;
    string s;cin >> s;
    f[0][0][k] = 1;
    for (int i = 0;i < n;++i) {
        for (int x = k;x >= 0;x--) {
            if (s[i] == '0') {
                newf[0][0][x] = (f[1][0][x] + f[0][0][x]) % mod;//100 000
                newf[1][0][x] = f[0][1][x];//010 x110x
                newf[0][1][x] = (f[1][0][x + 1] + f[0][0][x + 1]) % mod;//101 001
                newf[1][1][x] = (f[0][1][x + 1] + f[1][1][x + 1]) % mod;//011 111
            }
            else {
                newf[0][0][x] = (f[1][0][x + 1] + f[0][0][x + 1]) % mod;
                newf[1][0][x] = f[0][1][x + 1];//010
                newf[0][1][x] = (f[1][0][x] + f[0][0][x]) % mod;//101 001
                newf[1][1][x] = (f[0][1][x] + f[1][1][x]) % mod;//011 111
            }
        }
        for (int x = k;x >= 0;x--) {
            f[0][0][x] = newf[0][0][x];
            f[1][0][x] = newf[1][0][x];
            f[0][1][x] = newf[0][1][x];
            f[1][1][x] = newf[1][1][x];
        }
    }
    int ans = 0;
    for (int x = k;x >= 0;x--)
        ans = (ans + f[0][0][x] + f[1][0][x] + f[0][1][x] + f[1][1][x]) % mod;
    cout << ans;
    return 0;
}