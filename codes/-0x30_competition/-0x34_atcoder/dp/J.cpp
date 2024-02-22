#include <bits/stdc++.h>
#define int long long 
using namespace std;
constexpr int MAXN = 3e2 + 10, mod = 1e9 + 7;
double nums[MAXN], dp[MAXN][MAXN][MAXN];
int cnts[4], tmp;
int n;

double dfs(int a, int b, int c) {
    if (a < 0 || b < 0 || c < 0)return 0;
    if (a == 0 && b == 0 && c == 0)return 0;
    if (dp[a][b][c] != -1.0)return dp[a][b][c];
    double res = a * dfs(a - 1, b, c) + b * dfs(a + 1, b - 1, c) + c * dfs(a, b + 1, c - 1);
    return dp[a][b][c] = (res + n) / (a + b + c);
}

signed main() {
    ios::sync_with_stdio(false);
    cout.precision(20);
    cin >> n;
    for (int i = 0;i <= n;++i)for (int j = 0;j <= n;++j)for (int k = 0;k <= n;++k)
        dp[i][j][k] = -1;
    for (int i = 0;i < n;++i) {
        cin >> tmp;
        cnts[tmp]++;
    }
    cout << dfs(cnts[1], cnts[2], cnts[3]);
    return 0;
}