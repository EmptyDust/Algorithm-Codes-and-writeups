#include <bits/stdc++.h>
#define int long long 
using namespace std;
constexpr int MAXN = 1e6 + 10;
int n, nums[MAXN];
using pt = pair<int, int>;
pt pts[MAXN];

void solve() {
    int n;cin >> n;
    int sum = 0;
    for (int i = 0;i < n;++i)cin >> nums[i], sum += nums[i];
    int cnt = 0, x = sum / n;
    bool f = true;
    for (int i = 0;i < n;++i) {
        if (nums[i] > x) {
            cnt += nums[i] - x;
        }
        else {
            if (x - nums[i] > cnt) {
                f = false;
                break;
            }
            else {
                cnt += nums[i] - x;
            }
        }
    }
    cout << (f ? "YES" : "NO");
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