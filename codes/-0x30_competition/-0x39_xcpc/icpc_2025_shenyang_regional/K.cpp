#include<bits/stdc++.h>
#define int long long
#define fir first
#define sec second
using namespace std;
typedef long long ll;

using PII = pair<int, int>;

void __() {
    int n, k;
    cin >> n >> k;
    vector<PII> p1(n + 1);
    vector<PII> p2(n + 1);
    map<PII, int> mp;
    ll x = 0, y = 0;
    for (int i = 1; i <= n; i++) {
        cin >> p1[i].fir >> p1[i].sec;
        cin >> p2[i].fir >> p2[i].sec;
        mp[p2[i]] = i;

        x += p2[i].fir - p1[i].fir;
        y += p2[i].sec - p1[i].sec;
    }
    x /= 2;
    y /= 2;

    PII fin = { p1[k].fir + x, p1[k].sec + y };

    assert(mp.count(fin));
    cout << mp[fin] << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _ = 1;
    // cin>>_;
    while (_--) {
        __();
    }
}