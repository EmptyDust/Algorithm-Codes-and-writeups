#include <bits/stdc++.h>
//#define int long long 
using namespace std;
constexpr int MAXN = 1e3 + 10, mod = 1e9 + 7;
int mp[MAXN][MAXN], dp[MAXN];
vector<int> adj[MAXN];

signed main() {
    ios::sync_with_stdio(false);
    int a, b, k;cin >> a >> b >> k;
    cout << (a >= k * b ? "good" : "bad");

    return 0;
}