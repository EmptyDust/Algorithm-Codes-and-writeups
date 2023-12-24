#include <bits/stdc++.h>
#define int long long
#define ll long long
using namespace std;
constexpr int MAXN = 5e6 + 10;
int nums[MAXN], ans[MAXN], qey[MAXN], zbs[MAXN];

signed main() {
    ios::sync_with_stdio(false);
    int n, q;cin >> n >> q;
    for (int i = 0;i < n;++i)cin >> nums[i];
    for (int i = 0;i < q;++i)cin >> qey[i];
    iota(zbs, zbs + q, 0);
    sort(zbs, zbs + q, [&](int a, int b) {return qey[a] < qey[b];});
    sort(nums, nums + n);
    int sum = 0;
    for (int i = 0, j = 0;i < q;++i) {
        while (j < n && sum + nums[j] <= qey[zbs[i]]) {
            sum += nums[j++];
        }
        ans[zbs[i]] = j;
    }
    for (int i = 0;i < q;++i)cout << ans[i] << endl;
    return 0;
}