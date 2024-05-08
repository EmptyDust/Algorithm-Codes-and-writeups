#include<bits/stdc++.h>
#include<bits/extc++.h>
#define int long long

using namespace std;
using namespace __gnu_pbds;

#define x first
#define y second
#define ls(i) i<<1
#define rs(i) (i<<1)|1
#define lowbit(i) (i&(-i))

constexpr int MAXN = 1e6;
int nums[MAXN];

using pt = pair<int, int>;
using pat = pair<pt, int>;
using int_rb_tree = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

void solve() {
    int n;cin >> n;
    for (int i = 0;i < n;++i)cin >> nums[i];
    int m = LONG_LONG_MAX;
    int ans = 0;
    for (int i = 0;i < n;++i) {
        if (nums[i] <= m)m = nums[i];
        ans = max(ans, nums[i] - m);
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    solve();
    return 0;
}
