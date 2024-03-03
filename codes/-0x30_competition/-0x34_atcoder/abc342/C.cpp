#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int MAXN = 100;
int dsu[MAXN], n;
using pt = pair<int, int>;

signed main() {
    ios::sync_with_stdio(false);
    iota(dsu, dsu + 26, 0);
    int n;cin >> n;
    string s;cin >> s;
    int q;cin >> q;
    char cc, dc;
    while (q--) {
        cin >> cc >> dc;
        int c = cc - 'a', d = dc - 'a';
        for (int i = 0;i < 26;++i)if (dsu[i] == c)dsu[i] = d;
    }
    for (char ch : s) {
        int c = ch - 'a';
        cout << (char)('a' + dsu[c]);
    }
    return 0;
}