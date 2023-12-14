#include <bits/stdc++.h>
#define int long long
using namespace std;
struct point
{
    int x, y;
};
\

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t;cin >> t;
    while (t--) {
        int a, b;cin >> a >> b;
        int xk, yk, xq, yq;
        cin >> xk >> yk >> xq >> yq;
        vector<point> vpk, vpq, ans;
        int tmpx = INT_MAX, tmpy = INT_MAX;
        int cnt = 0;
        vpk.push_back({ xk - a,yk - b });
        vpk.push_back({ xk - a,yk + b });
        vpk.push_back({ xk + a,yk - b });
        vpk.push_back({ xk + a,yk + b });
        vpk.push_back({ xk - b,yk - a });
        vpk.push_back({ xk - b,yk + a });
        vpk.push_back({ xk + b,yk - a });
        vpk.push_back({ xk + b,yk + a });
        vpq.push_back({ xq - a,yq - b });
        vpq.push_back({ xq - a,yq + b });
        vpq.push_back({ xq + a,yq - b });
        vpq.push_back({ xq + a,yq + b });
        vpq.push_back({ xq - b,yq - a });
        vpq.push_back({ xq - b,yq + a });
        vpq.push_back({ xq + b,yq - a });
        vpq.push_back({ xq + b,yq + a });
        for (int i = 0;i < 8;++i) {
            for (int j = 0; j < 8; j++)
            {
                if (vpk[i].x == vpq[j].x && vpk[i].y == vpq[j].y) {
                    bool f = false;
                    for (int k = 0;k < ans.size();++k)
                        if (ans[k].x == vpk[i].x && ans[k].y == vpk[i].y)
                            f = true;
                    if (f)continue;
                    ans.push_back(vpk[i]);
                    cnt++;
                }
            }
        }
        cout << cnt << '\n';
    }
    return 0;
}