#include <bits/stdc++.h>
#define int long long 
using namespace std;
constexpr int MAXN = 1e6 + 10;
int nums[MAXN], n, f[MAXN];
using pt = pair<int, int>;

void solve() {
    int n, m;cin >> n >> m;
    for (int i = 0;i < n;++i)cin >> nums[i], f[i] = 0;
    int sum = 0;
    for (int i = 0;i < n;++i) {
        while (nums[i] % 10 == 0)f[i]++, nums[i] /= 10;
        sum += f[i];
        while (nums[i])sum++, nums[i] /= 10;
    }
    sort(f, f + n, greater<int>());
    for (int i = 0;i < n;i += 2) {
        sum -= f[i];
    }
    cout << (sum <= m ? "Anna" : "Sasha");
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