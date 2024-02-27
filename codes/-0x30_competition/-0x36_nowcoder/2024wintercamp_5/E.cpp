#include <bits/stdc++.h>
#define int long long 
using namespace std;
constexpr int MAXN = 1e5 + 10, mod = 1e9 + 7;
using pt = pair<int, int>;
int nums[MAXN];

void solve(int n) {
    for (int i = 1;i <= n;++i)cin >> nums[i];
    int m = 0;
    for (int i = 2;i < n;++i)
        m = max(nums[i - 1] - nums[i], m);
    cout << (nums[n - 1] + m * (n - 1) <= nums[n] ? "YES" : "NO");
}

signed main() {
    ios::sync_with_stdio(false);
    int t;cin >> t;
    while (t--) {
        int n;cin >> n;
        if (n % 2 == 0) cout << "YES";
        else solve(n);
        cout << '\n';
    }
    return 0;
}