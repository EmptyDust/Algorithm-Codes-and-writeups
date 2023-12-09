#include <bits/stdc++.h>
#define int long long
using namespace std;

#define x first
#define y second

int n, q;
string s;
using pt = pair<int, int>;
map<pt, vector<int>> mp;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> q;
    cin >> s;
    vector<pt> pos(n + 1);
    pos[0] = { 0,0 };
    for (int i = 0;i < n;++i) {
        pos[i + 1].x = pos[i].x + (s[i] == 'R') - (s[i] == 'L');
        pos[i + 1].y = pos[i].y + (s[i] == 'U') - (s[i] == 'D');
    }
    for (int i = 0; i <= n; i++) mp[pos[i]].push_back(i);
    auto check = [&](pt p, int l, int r) {
        if (!mp.count(p))return false;
        auto it = lower_bound(mp[p].begin(), mp[p].end(), l);
        return (it != mp[p].end() && *it <= r);
        };
    while (q--) {
        int x, y, l, r;
        cin >> x >> y >> l >> r;
        pt p = { x,y };
        pt pn = { pos[r].x - (x - pos[l - 1].x),pos[r].y - (y - pos[l - 1].y) };
        if (check(p, 0, l - 1) || check(pn, l, r - 1) || check(p, r, n))
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }
    return 0;
}