#include <bits/stdc++.h>
#define int long long
using namespace std;
int nums[1000000];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T;cin >> T;
    int res = 0;
    while (T--) {
        int n, l, r;
        cin >> n >> l >> r;
        l--, r--;
        for (int i = 0;i < n;++i)
            cin >> nums[i];
        int ans = 0;
        int cnt;
        for (int i = l; i <= r; i++)
        {
            cnt = 0;
            for (int j = i; j <= r; j++)
            {
                cnt += nums[j];
                if (cnt * 2 == j - i + 1)
                    ans = max(ans, j - i + 1);
            }
        }
        res ^= ans;
    }
    cout << res;
    return 0;
}