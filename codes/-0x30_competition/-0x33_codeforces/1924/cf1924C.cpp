#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int MAXN = 26 + 10, mod = 1e9 + 7;

using pt = pair<int, int>;

void solve() {
    int n, k, m;cin >> n >> k >> m;
    string s;cin >> s;
    map<int, int> ct;
    string ans;int cnt = 0, si = 0;
    for (int i = 0;i < m;++i) {
        int x = s[i] - 'a';
        ct[x]++;
        if (ct[x] == 1)si++;
        if (si == k) {
            si = 0;
            ct.clear();
            cnt++;
            ans += s[i];
        }
    }
    if (cnt >= n)cout << "YES";
    else {
        cout << "NO" << '\n';
        for (int i = 0;i < k;++i)if (!ct[i]) {
            ans += (char)(i + 'a');
            break;
        }
        for (int i = ans.length();i < n;++i)ans += 'a';
        cout << ans;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t;cin >> t;
    while (t--)solve(), cout << '\n';
    return 0;
}