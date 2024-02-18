#include <bits/stdc++.h>
#define int long long 
using namespace std;
constexpr int MAXN = 1e6 + 10;
int nums[MAXN];

void solve() {
    int n;cin >> n;
    for (int i = 0;i < n;++i)cin >> nums[i];
    vector<int> cnts(26, -1);
    for (int i = 0;i < n;++i) {
        for (int j = 0;j < 26;++j)if (cnts[j] == nums[i] - 1) {
            cnts[j]++;
            cout << (char)('a' + j);
            break;
        }
    }
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