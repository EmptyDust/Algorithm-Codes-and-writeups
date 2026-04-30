#include <bits/stdc++.h>
#define int long long 
using namespace std;
constexpr int MAXN = 1e6 + 10;
int nums[MAXN], n;
using pt = pair<int, int>;

void solve() {
    int n, k;
    cin >> n >> k;
    int x = n / k, b = n % k, len = x + (b != 0);
    int t = 1;
    for (int i = 1;i <= k;++i) {
        if (i & 1)
            for (int j = i;j <= n;j += k) {
                nums[j] = t++;
            }
        else {
            int f = t + x + (b >= i) - 1;
            t = f + 1;
            for (int j = i;j <= n;j += k)
                nums[j] = f--;
        }
    }
    for (int i = 1;i <= n;++i)cout << nums[i] << ' ';
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