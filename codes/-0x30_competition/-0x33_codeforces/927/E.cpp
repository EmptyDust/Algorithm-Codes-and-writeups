#include <bits/stdc++.h>
#define int long long 
using namespace std;
constexpr int MAXN = 1e6 + 10;
int nums[MAXN], n, mul[MAXN];
using pt = pair<int, int>;

void solve() {
    int n;cin >> n;
    string s;cin >> s;
    vector<int> nums;
    for (char ch : s)nums.push_back(ch - '0');
    vector<int> sums(nums.size());
    int sum = 0;
    for (int i = 0;i < nums.size();++i)sums[i] = sum += nums[i];
    reverse(sums.begin(), sums.end());
    int y = 0;
    vector<int> ans(nums.size() + 10);
    int i = 0;
    for (;i < sums.size();++i) {
        y += sums[i];
        ans[i] = y % 10;
        y /= 10;
    }
    while (y)ans[i] = y % 10, y /= 10;
    reverse(ans.begin(), ans.end());
    bool lead0 = true;
    for (int num : ans) {
        if (lead0 && num == 0)continue;
        else {
            lead0 = false;
            cout << num;
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