//lgp1011 day0B by Empty_Dust
#include <bits/stdc++.h>
#define int long long
using namespace std;
using pt = pair<int, int>;
pt pts[30];

signed main() {
    ios::sync_with_stdio(false);
    int a, n, m, x;
    cin >> a >> n >> m >> x;
    if (x == 1 || x == 2) { cout << a;return 0; }
    pts[1] = { 1,0 }, pts[2] = { 0,1 };
    for (int i = 3;i <= n;++i)pts[i] = { pts[i - 1].first + pts[i - 2].first,pts[i - 1].second + pts[i - 2].second };
    pt ptm = { 1,0 };
    for (int i = 3;i < n;++i)ptm = { ptm.first + pts[i - 2].first,ptm.second + pts[i - 2].second };
    int b = (m - a * ptm.first) / ptm.second;
    pt ans = { 1,0 };
    for (int i = 3;i <= x;++i)ans = { ans.first + pts[i - 2].first,ans.second + pts[i - 2].second };
    cout << a * ans.first + b * ans.second;
    return 0;
}