#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int MAXN = 12 + 10;
int f[MAXN][MAXN], num[MAXN], digit;

int dfs(int pos, int sum, bool lead0, bool lim) {
    if (!pos)return sum;
    int& cur = f[pos][sum];
    if (!lead0 && !lim && ~cur)return cur;
    int up = lim ? num[pos] : 9, res = 0;
    for (int i = 0;i <= up;++i)
        res += dfs(pos - 1, sum + (!lead0 && i == digit), lead0 && !i, lim && i == up);
    if (!lead0 && !lim)cur = res;
    return res;
}

vector<int> solve(int x) {
    int len = 0;
    while (x)num[++len] = x % 10, x /= 10;
    vector<int> ret(10);
    for (int i = 0;i <= 9;++i) {
        digit = i;
        memset(f, -1, sizeof f);
        ret[i] = dfs(len, 0, !i, 1);
    }
    return ret;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int a, b;cin >> a >> b;
    vector<int> l, r;
    l = solve(a - 1);
    r = solve(b);
    for (int i = 0;i <= 9;++i)
        cout << r[i] - l[i] << ' ';
    return 0;
}