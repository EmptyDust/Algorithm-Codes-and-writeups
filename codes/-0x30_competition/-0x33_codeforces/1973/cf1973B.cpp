#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
    int T;cin >> T;
    while (T--)
    {
        int n;cin >> n;
        vector<int> mp(n + 1), re(21, 0);
        for (int i = 1;i <= n;++i)cin >> mp[i];
        for (int i = 0;i < 20;++i)
        {
            int t = 0;
            for (int j = 1;j <= n;++j)
            {
                if (mp[j] >> i & 1)re[i] = max(re[i], j - t), t = j;
            }
            if (t != 0)re[i] = max(re[i], n - t + 1);
        }
        int ans = 0;
        for (int i = 0;i < 20;++i)
        {
            ans = max(ans, re[i]);
            //cout << re[i] << " ";
        }
        cout << (ans == 0 ? 1 : ans) << endl;
    }
    return 0;
}