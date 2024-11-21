#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n; cin >> n;
    string s; cin >> s;
    int visr = 0, visb = 0, ok = 0;
    for (int i = 0;i < n;i++) {
        if (s[i] == s[(i + 1) % n]) {
            if (s[i] == 'R') visr = 1;
            else visb = 1;
            ok++;
        }
    }
    if (visr & visb) {
        cout << "NO\n";
        return;
    }
    if (ok == n) {
        cout << "YES\n";
        return;
    }
    if (visb) for (int i = 0;i < n;i++) s[i] = 'R' + 'B' - s[i];
    int st = 0;
    for (int i = 0;i < n;i++) if (s[i] == 'B') st = (i + 1) % n;
    vector<int> vc;
    int ntot = 0, cnt = 0;
    for (int i = 0, j = st;i < n;i++, j = (j + 1) % n) {
        if (s[j] == 'B') vc.push_back(ntot), cnt += (ntot & 1) ^ 1, ntot = 0;
        else ntot++;
    }
    if (vc.size() == 1 || cnt == 1) {
        cout << "YES\n";
        return;
    }
    cout << "NO\n";
    return;
}
signed main() {
    int t; cin >> t;
    while (t--) solve();
    return 0;
}