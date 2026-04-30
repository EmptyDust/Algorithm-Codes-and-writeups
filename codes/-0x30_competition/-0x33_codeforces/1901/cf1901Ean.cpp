#include <bits/stdc++.h>
 
using namespace std;
 
using li = long long;
 
const li INF = 1e18;
const int N = 555555;
 
int n;
int a[N];
vector<int> g[N];
li dp[N];
li ans;
 
void calc(int v, int p) {
  vector<li> sum(4, -INF);
  sum[0] = 0;
  for (int u : g[v]) if (u != p) {
    calc(u, v);
    for (int i = 3; i >= 0; --i) {
      sum[min(i + 1, 3)] = max(sum[min(i + 1, 3)], sum[i] + dp[u]);
    }
  }
  dp[v] = -INF;
  for (int j = 0; j < 4; ++j) {
    dp[v] = max(dp[v], sum[j] + (j == 1 ? 0 : a[v]));
    ans = max(ans, sum[j] + (j == 2 ? 0 : a[v]));
  }
}
 
int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) g[i].clear();
    for (int i = 0; i < n - 1; ++i) {
      int x, y;
      cin >> x >> y;
      --x; --y;
      g[x].push_back(y);
      g[y].push_back(x);
    }
    ans = 0;
    calc(0, -1);
    cout << ans << '\n';
  }
}