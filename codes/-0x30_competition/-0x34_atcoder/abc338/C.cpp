#include <bits/stdc++.h>
#define int long long 
using namespace std;
constexpr int MAXN = 10 + 100;
int q[MAXN], a[MAXN], b[MAXN], n;
using pt = pair<int, int>;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 0;i < n;++i)cin >> q[i];
    for (int i = 0;i < n;++i)cin >> a[i];
    for (int i = 0;i < n;++i)cin >> b[i];
    int ans = 0;
    for (int x = 0;;++x) {
        bool valid = true;
        int cut = INT_MAX;
        for (int i = 0;i < n;++i) {
            int tmp = q[i] - a[i] * x;
            if (tmp < 0) {
                valid = false;
                break;
            }
            if (b[i])cut = min(cut, tmp / b[i]);
        }
        if (!valid)break;
        ans = max(cut + x, ans);
    }
    cout << ans;
    return 0;
}