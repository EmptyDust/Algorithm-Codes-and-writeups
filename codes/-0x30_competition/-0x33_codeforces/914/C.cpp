#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int MAXN = 2e6;
int nums[MAXN];

void solve() {
    int n, k;cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    if (k >= 3) {
        cout << 0;
        return;
    }
    sort(nums, nums + n);
    int m = nums[0];
    for (int i = 1;i < n;++i)
        m = (nums[i] - nums[i - 1] < m ? nums[i] - nums[i - 1] : m);
    if (k == 1) {
        cout << m;
        return;
    }
    for (int i = 0;i < n;++i) for (int j = i + 1; j < n; j++)
    {

        int cut = nums[j] - nums[i];

        auto lbz = lower_bound(nums, nums + n, cut);

        int lb = *lbz;
        int ub = *(lbz - 1);
        int x = abs(lb - cut);
        int y = abs(ub - cut);
        //if (cut == 10)
          //  cout << m << ' ' << lb << ' ' << x << ' ' << ub << ' ' << y << endl;
        int tmp = (x < y ? x : y);
        m = tmp < m ? tmp : m;
    }
    cout << m;
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