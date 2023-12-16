#include <bits/stdc++.h>
//#define int long long
using namespace std;
constexpr int MAXN = 1e6;
vector<int> potions[MAXN];
int ans[MAXN];

signed main() {
    ios::sync_with_stdio(false);
    int n, t, x;
    cin >> n;
    for (int i = 0;i < n;++i) {
        cin >> t >> x;
        if (t == 1) {
            potions[x].push_back(i);
            ans[i] = 0;
        }
        else {
            ans[i] = -1;
            if (potions[x].empty()) {
                cout << -1;
                return 0;
            }
            ans[potions[x][potions[x].size() - 1]] = 1;
            potions[x].pop_back();
        }
    }
    int ret = 0, sum = 0;
    for (int i = 0;i < n;++i) {
        sum += ans[i];
        ret = max(ret, sum);
    }
    cout << ret << '\n';
    for (int i = 0;i < n;++i) {
        if (ans[i] != -1)
            cout << ans[i] << ' ';
    }

    return 0;
}