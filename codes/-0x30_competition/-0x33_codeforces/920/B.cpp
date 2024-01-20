#include <bits/stdc++.h>
#define int long long 
using namespace std;
constexpr int MAXN = 1e6;
int nums[MAXN];
using pt = pair<int, int>;

void solve() {
    int n;cin >> n;
    string s1, s2;cin >> s1 >> s2;
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0;i < n;++i) {
        if (s1[i] == s2[i])continue;
        if (s1[i] == '1' && s2[i] == '0')cnt1++;
        if (s2[i] == '1' && s1[i] == '0')cnt2++;
    }
    cout << min(cnt1, cnt2) + abs(cnt1 - cnt2);
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