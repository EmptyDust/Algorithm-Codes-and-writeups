#include <bits/stdc++.h>
#define int long long
using namespace std;
#define x first
#define y second
constexpr int MAXN = 1e6;
constexpr int mod = 1e9 + 7;
using pt = pair<int, int>;
int nums[MAXN][3];
int mxs[3][3];

void solve() {
    int n;cin >> n;
    for (int j = 0;j < 3;++j)for (int i = 0;i < n;++i)cin >> nums[i][j];
    for (int i = 0;i < 3;++i)for (int j = 0;j < 3;++j)mxs[i][j] = -1;
    for (int j = 0;j < 3;++j) {
        for (int i = 0;i < n;++i) {
            int tmp = i;
            for (int k = 0;k < 3;++k) {
                if (mxs[k][j] == -1 || nums[tmp][j] > nums[mxs[k][j]][j])
                    swap(tmp, mxs[k][j]);
            }
        }
    }
    int ret = 0;
    for (int i = 0;i < 3;++i) {
        for (int j = 0;j < 3;++j) {
            if (mxs[i][0] == mxs[j][1])continue;
            for (int k = 0;k < 3;++k) {
                if (mxs[i][0] == mxs[k][2] || mxs[j][1] == mxs[k][2])continue;
                ret = max(ret, nums[mxs[i][0]][0] + nums[mxs[j][1]][1] + nums[mxs[k][2]][2]);
            }
        }
    }
    cout << ret;
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