#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int MAXN = 6e6, mod = 1e9 + 7;
int nums[MAXN];
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
    int cnt = 0;
    bool f = false;
    for (int i = 0;i < n;++i) {
        cin >> nums[i];
        if (nums[i] < 0)cnt++;
        if (nums[i] == 0)f = true;
    }
    if (cnt & 1 || f)cout << 0;
    else {
        cout << 1 << endl;
        cout << 1 << ' ' << 0;
    }
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