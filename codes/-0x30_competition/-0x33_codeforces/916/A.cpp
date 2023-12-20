#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int MAXN = 1e6;
constexpr int mod = 1e9 + 7;
using pt = pair<int, int>;
int nums[26] = { 0 };

void solve() {
    int n;cin >> n;
    string s;cin >> s;
    for (int i = 0;i < 26;++i)nums[i] = 0;
    for (char ch : s) {
        nums[ch - 'A']++;
    }
    int cnt = 0;
    for (int i = 1;i <= 26;++i) {
        if (nums[i - 1] >= i)cnt++;
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