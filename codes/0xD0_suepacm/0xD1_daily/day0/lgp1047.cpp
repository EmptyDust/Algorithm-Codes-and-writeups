//lgp1047 day0A by Empty_Dust
#include <bits/stdc++.h>
#define int long long
using namespace std;
#define pre first
#define suf second
using pt = pair<int, int>;

signed main() {
    ios::sync_with_stdio(false);
    int s, m;cin >> s >> m;
    vector<pt> pts(m);
    for (int i = 0;i < m;++i)cin >> pts[i].pre >> pts[i].suf;
    int l = 0, r = -1;
    sort(pts.begin(), pts.end(), [&](pt a, pt b) {return a.pre < b.pre;});
    int sum = 0;
    for (int i = 0;i < m;++i) {
        pt& cut = pts[i];
        if (r < cut.pre) { sum += r - l + 1;l = cut.pre;r = cut.suf; }
        if (r < cut.suf)r = cut.suf;
    }
    sum += r - l + 1;
    cout << s + 1 - sum;
    return 0;
}