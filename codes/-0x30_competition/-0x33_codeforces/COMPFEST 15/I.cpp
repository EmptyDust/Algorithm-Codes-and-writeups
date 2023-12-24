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
    for (int i = n, j = m;i > 0 && j > 0;i--, j--) {
        while (i > 0 && j > 0 && (ns[i] >= j || ms[j] >= i)) {
            if (i > 0 && ns[i] >= j)--i;
            if (j > 0 && ms[j] >= i)--j;
        }
        if (i == 1 && j == 1)f = true;
        //cout << i << ' ' << j << endl;
    }
    if (f)cout << "Bhinneka";
    else cout << "Chaneka";
    return 0;
}