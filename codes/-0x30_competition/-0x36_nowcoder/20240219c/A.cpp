#include <bits/stdc++.h>
#define int long long 
using namespace std;
constexpr int MAXN = 1e6 + 10;
int nums[MAXN], n;
using pt = pair<int, int>;

void solve() {
    cin >> n;
    int cnt = 0;
    string s;
    while (n--) {
        cin >> s;
        s = s.substr(0, 5);
        if (s == "bnu16")cnt++;
    }
    cout << cnt;
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