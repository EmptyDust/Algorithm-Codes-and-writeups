#include <bits/stdc++.h>
#define int long long 
using namespace std;
constexpr int MAXN = 1e6 + 10, mod = 1e9 + 7, inf = 1e9;
int a[MAXN], b[MAXN];
vector<int> adj[MAXN];

int sub_seq_max(int nums[MAXN], int n) {
    int mx = -inf, cur = 0;
    for (int i = 0;i < n;++i) {
        mx = max(mx, cur + nums[i]);
        cur = max((int)0, cur + nums[i]);
    }
    return mx;
}

int sub_seq_min(int nums[MAXN], int n) {
    int mn = inf, cur = 0;
    for (int i = 0;i < n;++i) {
        mn = min(mn, cur + nums[i]);
        cur = min((int)0, cur + nums[i]);
    }
    return mn;
}

signed main() {
    ios::sync_with_stdio(false);
    int m, n;cin >> m >> n;
    int ama = inf, bma = inf;
    for (int i = 0;i < m;++i)cin >> a[i], ama = min(ama, abs(a[i]));
    for (int i = 0;i < n;++i)cin >> b[i], bma = min(bma, abs(b[i]));
    int ans = max(sub_seq_max(a, m) * sub_seq_max(b, n), sub_seq_min(a, m) * sub_seq_min(b, n));
    ans = max(-ama * bma, ans);
    cout << ans;
    return 0;
}