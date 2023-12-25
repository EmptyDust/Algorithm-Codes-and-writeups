#include <bits/stdc++.h>
//#define int long long
using namespace std;
using pt = pair<int, int>;
constexpr int MAXN = 2e5 + 10;
int ns[MAXN], ms[MAXN];

signed main() {
    ios::sync_with_stdio(false);
    int n, m, k, x, y;
    cin >> n >> m >> k;
    for (int i = 0;i <= n;++i)ns[i] = -1;
    for (int j = 0;j <= m;++j)ms[j] = -1;
    while (k--) {
        cin >> x >> y;
        ns[x] = max(ns[x], y), ms[y] = max(ms[y], x);
    }
    bool f = false;
    for (int i = n, j = m;i > 0 && j > 0;) {
        if (i <= ms[j] && j <= ns[i])--i, --j;
        else if (i <= ms[j])--j;
        else if (j <= ns[i])--i;
        else {
            if (i == 1 && j == 1)f = true;
            --i, --j;
        }
    }
    if (f)cout << "Bhinneka";
    else cout << "Chaneka";
    return 0;
}