#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int MAXN = 1e6;
int stk[MAXN];

void solve() {
    int n;cin >> n;
    string s;cin >> s;

    int ski = 0, skj = 0;
    for (int i = 0;i < n;++i) {
        while (ski > 0 && s[stk[ski - 1]] < s[i])ski--;
        stk[ski++] = i;
    }
    while (skj < ski - 1 && s[stk[skj]] == s[stk[skj + 1]]) skj++;
    for (int i = 0, j = ski - 1;i < j;++i, --j)swap(s[stk[i]], s[stk[j]]);
    for (int i = 1;i < n;++i)if (s[i] < s[i - 1]) {
        cout << -1;
        return;
    }
    cout << ski - skj - 1;
}

signed main() {
    ios::sync_with_stdio(false);
    int t;cin >> t;
    while (t--) {
        solve();
        cout << '\n';
    }
    return 0;
}