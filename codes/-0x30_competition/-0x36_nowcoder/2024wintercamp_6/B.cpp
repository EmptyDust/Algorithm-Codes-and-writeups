#include <bits/stdc++.h>
#define int long long 
using namespace std;
constexpr int MAXN = 1e6 + 10, mod = 1e9 + 7;
int a[MAXN], b[MAXN], zbs[MAXN];
vector<int> adj[MAXN];

signed main() {
    ios::sync_with_stdio(false);
    int n;cin >> n;
    for (int i = 0;i < n;++i)cin >> a[i];
    for (int i = 0;i < n;++i)cin >> b[i];
    sort(a, a + n);
    iota(zbs, zbs + n, 0);
    sort(zbs, zbs + n, [&](int x, int y) { return b[x] < b[y]; });
    sort(b, b + n);
    int ans = 1e9, ansi = -1, ansj = -1;
    for (int i = 0, j = 0;i < n && j < n;++j) {
        while (i < n && a[i] < b[j])++i;
        if (i > 0 && abs(a[i - 1] - b[j]) < ans) {
            ans = abs(a[i - 1] - b[j]);
            ansi = i - 1;
            ansj = zbs[j];
        }
        if (i < n && abs(a[i] - b[j]) < ans) {
            ans = abs(a[i] - b[j]);
            ansi = i;
            ansj = zbs[j];
        }
    }
    swap(a[ansi], a[ansj]);
    for (int i = 0;i < n;++i)cout << a[i] << ' ';
    return 0;
}