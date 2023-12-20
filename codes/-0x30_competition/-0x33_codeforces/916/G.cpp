#include <bits/stdc++.h>
#define int long long
using namespace std;
using pt = pair<int, int>;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
constexpr int MAXN = 1e6, mod = 998244353;
int r[MAXN], f[MAXN], nums[MAXN];
int cnt, ans, x, n, t;
map<int, int> last;

void solve() {
    cin >> n;
    for (int i = 0;i < n;++i)r[i] = rng();
    f[0] = 0, cnt = 0;
    last.clear();
    for (int i = 0;i < 2 * n;++i) {
        cin >> nums[i];
        nums[i]--;
        f[i + 1] = f[i] ^ r[nums[i]];
        last[f[i + 1]] = i + 1;
        if (f[i + 1] == 0)cnt++;
    }
    cout << cnt << ' ';
    ans = 1;
    for (int i = 0;i < n * 2;++i)if (f[i] == 0) {
        cnt = 1;
        x = i + 1;
        while (f[x] != 0) {
            x = last[f[x]] + 1;
            cnt++;
        }
        ans *= cnt;
        ans %= mod;
    }
    cout << ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while (t--) {
        solve();
        cout << '\n';
    }
    return 0;
}