#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int MAXN = 1e6 + 10, inf = 1e8;
int nums[MAXN], s[MAXN], n;
using pt = pair<int, int>;

int cal(int l, int r, int v) {
    if (l < 0 || r >= n || l>r)return -inf;
    int len = s[r] - s[l] + nums[r];
    int m = v - len + 1;
    int ans = (v + m) * len / 2;
    //cout << len << endl;
    return ans;
}

void solve() {
    cin >> n;
    for (int i = 0;i < n;++i)cin >> nums[i];
    int sum = 0;
    for (int i = 1;i < n;++i)s[i] = s[i - 1] + nums[i - 1];
    int q;cin >> q;
    int il, v;
    while (q--) {
        cin >> il >> v;il--;
        int l = il, r = n - 1, f = s[il] + v;
        while (l < r) {
            int mid = l + r >> 1;
            if (s[mid] >= f)r = mid;
            else l = mid + 1;
        }
        l--;
        int a[3] = { cal(il,l - 1,v),cal(il,l,v),cal(il,l + 1,v) };
        //cout << a[0] << ' ' << a[1] << ' ' << a[2] << endl;
        int ans = 0;
        for (int i = 1;i <= 2;++i) {
            if (a[i] > a[ans])ans = i;
        }
        cout << l + ans << ' ';
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