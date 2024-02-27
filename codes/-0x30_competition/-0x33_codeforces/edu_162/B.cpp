#include <bits/stdc++.h>
#define int long long 
using namespace std;
constexpr int MAXN = 1e6 + 10;
int nums[MAXN], a[MAXN], b[MAXN], n;
using pt = pair<int, int>;

bool solve() {
    int n, k;cin >> n >> k;
    for (int i = 1;i <= n;++i)nums[i] = 0;
    for (int i = 1;i <= n;++i)cin >> a[i];
    for (int i = 1;i <= n;++i)cin >> b[i];
    for (int i = 1;i <= n;++i)nums[abs(b[i])] += a[i];
    int cnt = 0;
    for (int i = 1;i <= n;++i) {
        cnt += k;
        cnt -= nums[i];
        if (cnt < 0)return 0;
    }
    return 1;
}

signed main() {
    ios::sync_with_stdio(false);
    int t;cin >> t;
    while (t--) {
        cout << (solve() ? "YES" : "NO");
        cout << '\n';
    }
    return 0;
}