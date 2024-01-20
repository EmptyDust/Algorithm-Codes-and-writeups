#include <bits/stdc++.h>
#define int long long 
using namespace std;
constexpr int MAXN = 1e5 + 500;
int nums[MAXN], mp[(int)400][MAXN], pre[(int)400][MAXN];
using pt = pair<int, int>;
int n, sq;

void qry(int start, int step, int count) {
    if (count == 1) {
        cout << nums[start];
        return;
    }
    if (step > sq) {
        int sum = 0;
        for (int i = start, k = 1;k <= count;i += step, k++)sum += nums[i] * k;
        cout << sum;
        return;
    }
    int zb = ceil(n / (double)step) * (start % step);
    int cur = start / step;
    int l = zb + cur, r = l + count;
    cout << mp[step][r] - (l == zb ? 0 : mp[step][l]) - cur * (pre[step][r] - (l == zb ? 0 : pre[step][l]));
}

void solve() {
    int q;cin >> n >> q;
    for (int i = 0;i < n;++i)cin >> nums[i];
    sq = ceil(sqrt(n));
    for (int i = 1;i <= sq;++i) {
        int step = ceil(n / (double)i);
        for (int t = 0;t < i;++t) {
            int cur = 0, k = 1, precur = 0;
            for (int j = t;j < n;j += i, k++) {
                mp[i][t * step + k] = cur += k * nums[j];
                pre[i][t * step + k] = precur += nums[j];
            }
        }
    }
    while (q--) {
        int s, d, k;
        cin >> s >> d >> k;
        s--;
        qry(s, d, k);
        cout << ' ';
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