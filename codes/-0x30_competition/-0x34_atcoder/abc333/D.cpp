#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int MAXN = 1e6;
vector<int> mp[MAXN];

int getnum(int x, int par) {
    int sum = 1;
    for (int num : mp[x]) if (num != par) {
        sum += getnum(num, x);
    }
    return sum;
}

signed main() {
    ios::sync_with_stdio(false);
    int n;cin >> n;
    for (int i = 0;i < n - 1;++i) {
        int u, v;cin >> u >> v;
        u--, v--;
        mp[u].push_back(v);
        mp[v].push_back(u);
    }
    int ans = 0;
    for (int num : mp[0]) {
        ans = max(ans, getnum(num, 0));
    }
    cout << n - ans;
    return 0;
}