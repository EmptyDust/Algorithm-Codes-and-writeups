#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int MAXN = 6e6;
int nums[MAXN], dp[MAXN];

void solve() {
    int n;cin >> n;
    for (int i = 0;i < n;++i)cin >> nums[i];
    int cut = 0, sum = 0;

    for (int i = 1;i < n;++i) {
        int a = ceil(log2((double)nums[i - 1] / nums[i]));
        if (a + cut > 0) {
            cut += a;
            sum += cut;
        }
        else cut = 0;
    }
    cout << sum;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t;cin >> t;
    while (t--) {
        solve();
        cout << '\n';
    }
    return 0;
}