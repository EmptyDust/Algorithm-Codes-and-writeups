#include<bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve()
{
    i64 n;
    string s;
    cin >> n >> s;
    s = " " + s;

    vector<i64> cl(n + 1), cr(n + 1);
    vector<i64> sl(1), sr(1);
    vector<i64> res(n + 1);

    for (i64 i = 1; i <= n; i++)
    {
        if (s[i] == '<') cl[i] = 1, sl.push_back(sl.back() + i), s[i] = 1;
        else cr[i] = 1, sr.push_back(sr.back() + i), s[i] = -1;
        cl[i] += cl[i - 1], cr[i] += cr[i - 1];
    }

    for (i64 i = 1; i < sl.size(); i++)
        res[i] = (i64)s[i] * i + (sl[i] - sl[cl[i]] - sr[cr[i - 1]]) * 2ll;
    for (i64 i = sl.size(); i <= n; i++)
        res[i] = (i64)s[i] * i + (n + 1ll) + (sl[(i64)sl.size() - 1] - sl[cl[i]] + sr[max(i - 1 - (i64)sl.size() + 1, 0ll)] - sr[cr[i - 1]]) * 2ll;
    for (i64 i = 1; i <= n; i++)
        cout << res[i] << " \n"[i == n];
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    i64 T = 1; cin >> T;
    while (T--)solve();
    return 0;
}