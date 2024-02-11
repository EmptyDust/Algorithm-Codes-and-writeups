#include <bits/stdc++.h>
#define int long long
using namespace std;

bool f(string& s, string& str) {
    int n = s.length(), m = str.length();
    int i = 0, j = 0;
    for (;i < n && j < m;++i)
        if (s[i] == str[j])++j;
    return j == m;
}

int solve() {
    int n;cin >> n;
    string s;cin >> s;
    string u = "DFS", l = "dfs";
    cout << f(s, u) << ' ' << f(s, l);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t;cin >> t;
    while (t--) {
        solve();
        cout << '\n';
    }
    return 0;
}