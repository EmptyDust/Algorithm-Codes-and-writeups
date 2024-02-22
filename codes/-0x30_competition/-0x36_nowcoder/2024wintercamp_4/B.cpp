#include <bits/stdc++.h>
//#define int long long 
using namespace std;
constexpr int MAXN = 1e3 + 10, mod = 1e9 + 7;
int mp[MAXN][MAXN], dp[MAXN];
vector<int> adj[MAXN];

signed main() {
    ios::sync_with_stdio(false);
    int n, tmp;cin >> n;
    bool f = 0;
    for (int i = 0;i < n;++i) {
        cin >> tmp;
        f = (tmp - 1 + f) % 2;
    }
    cout << (f ? "gui" : "sweet");
    return 0;
}