#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int MAXN = 6e6, mod = 1e9 + 7;
int nums[MAXN], v[MAXN];

void solve() {
    int n;cin >> n;
    for (int i = 0;i < n;++i)cin >> nums[i];
    stack<int> stk;
    for (int i = 0;i < n;++i) {
        while (!stk.empty() && 0 <= stk.top() - nums[i] && stk.top() - nums[i] <= 1) {
            
        }
    }
    cout << (stk.size() == 1 ? "Yes" : "No");
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