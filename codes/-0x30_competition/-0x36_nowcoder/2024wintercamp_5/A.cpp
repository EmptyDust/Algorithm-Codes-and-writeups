#include <bits/stdc++.h>
//#define int long long 
using namespace std;
constexpr int MAXN = 1e3 + 10, mod = 1e9 + 7;
int mp[MAXN][MAXN], dp[MAXN];
vector<int> adj[MAXN];

signed main() {
    ios::sync_with_stdio(false);
    int n;cin >> n;
    int cnt = 0, tmp;
    for (int i = 0;i < n;++i) {
        cin >> tmp;
        if (tmp != 1)cnt++;
    }
    cout << cnt;
    return 0;
}