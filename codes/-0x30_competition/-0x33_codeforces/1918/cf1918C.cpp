#include <bits/stdc++.h>
#define int long long 
using namespace std;
constexpr int MAXN = 64 + 10;
int a[MAXN], b[MAXN], r[MAXN], ans[MAXN], pow2[MAXN];
using pt = pair<int, int>;

int cal(int x, int num[MAXN]) {
    int len = 0;
    while (x) { num[++len] = x % 2;x >>= 1; }
    return len;
}

int recal(int num[MAXN]) {
    int ret = 0;
    for (int i = 1;i < 64;++i) {
        ret += pow2[i] * num[i];
    }
    return ret;
}

void solve() {
    int an, bn, rn;
    cin >> an >> bn >> rn;
    if (an < bn)swap(an, bn);
    int lena = cal(an, a), lenb = cal(bn, b), lenr = cal(rn, r);
    bool f = lena == lenb;
    int n = max(lena, lenb);
    if (f)
        while (n > 0 && a[n] == b[n]) n--;
    while (n--)
        if (a[n] == 1 && b[n] == 0)ans[n] = 1;
    for (int i = MAXN - 1;i;--i) {
        if (!r[i] && ans[i])ans[i] = false;
        if (r[i] && !ans[i])break;
    }
    int res = recal(ans);
    cout << abs((an ^ res) - (bn ^ res));
}

signed main() {
    ios::sync_with_stdio(false);
    pow2[1] = 1;
    for (int i = 2;i < 64;++i)
        pow2[i] = pow2[i - 1] << 1;
    int t;cin >> t;
    while (t--) {
        memset(a, 0, sizeof a);
        memset(b, 0, sizeof b);
        memset(r, 0, sizeof r);
        memset(ans, 0, sizeof ans);
        solve();
        cout << '\n';
    }
    return 0;
}