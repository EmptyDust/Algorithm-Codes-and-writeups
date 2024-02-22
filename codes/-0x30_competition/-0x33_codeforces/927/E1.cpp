#include <bits/stdc++.h>
#define int long long 
using namespace std;
constexpr int MAXN = 1e6 + 10;
int nums[MAXN], n, mul[MAXN];
using pt = pair<int, int>;

void solve() {
    int n;cin >> n;
    string s;cin >> s;
    int ans = 0;
    int pos = 1, mul = 0;
    for (int i = s.length() - 1;~i;--i) {
        int num = s[i] - '0';
        ans += pos * num + mul * num;
        mul = mul * 10 + pos * 9;
        pos++;
    }
    cout << ans;
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