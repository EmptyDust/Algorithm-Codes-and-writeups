#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int MAXN = 1e6 + 10;
int nums[MAXN], n;
using pt = pair<int, int>;

bool solve() {
    int n;cin >> n;
    for (int i = 0;i < n;++i)cin >> nums[i];
    sort(nums, nums + n);
    if (nums[0] != nums[1])return 1;
    for (int i = 1;i < n;++i) {
        if (nums[i] % nums[0])return 1;
    }
    return 0;
}

signed main() {
    ios::sync_with_stdio(false);
    int t;cin >> t;
    while (t--) {
        cout << (solve() ? "Yes" : "No");
        cout << '\n';
    }
    return 0;
}