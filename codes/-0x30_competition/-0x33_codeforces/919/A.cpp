#include <bits/stdc++.h>
#define int long long 
using namespace std;

void solve() {
    int h = INT_MAX, l = 0;
    int n;cin >> n;
    vector<int> nums;
    while (n--) {
        int op, x;
        cin >> op >> x;
        if (op == 1)l = max(l, x);
        if (op == 2)h = min(h, x);
        if (op == 3)nums.push_back(x);
    }
    int cnt = h - l + 1;
    for (int num : nums) {
        if (num <= h && num >= l)cnt--;
    }
    cout << (cnt > 0 ? cnt : 0);
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