#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int MAXN = 6e6, mod = 1e9 + 7;
int dp[MAXN];
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int qpow(int a, int n) {
    int res = 1;
    while (n) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod; n >>= 1;
    }
    return res;
}

#define inv(a) qpow(a,mod-2)  

void solve() {
    int n;cin >> n;
    string s;cin >> s;
    int chs[26] = { 0 };
    for (int i = 0;i < 26;++i)chs[i] = 0;
    int cnt = 0, sum = 0;
    for (char ch : s) {
        if (chs[ch - 'a'] == 0) {
            chs[ch - 'a'] = 1;
            cnt++;
        }
        sum += cnt;
    }
    cout << sum;
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