#include <bits/stdc++.h>
#define int long long 
using namespace std;
constexpr int MAXN = 1e6 + 10;
int nums[MAXN], n, mod, zbs[MAXN], ans[MAXN];
using pt = pair<int, int>;

void solve() {
    cin >> n >> mod;
    for (int i = 0;i < n;++i)cin >> nums[i];
    string s;cin >> s;
    for (int i = 0, l = 0, r = n - 1;i < n;++i) {
        if (s[i] == 'L')
            zbs[i] = l++;
        else
            zbs[i] = r--;
    }
    int res = 1;
    for (int i = n - 1;~i;--i) {
        ans[i] = res = res * nums[zbs[i]] % mod;
    }
    for (int i = 0;i < n;++i)cout << ans[i] << " ";
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