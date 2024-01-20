#include<bits/stdc++.h>
#define int long long 
using namespace std;
constexpr int MAXN = 1e6;
int nums[MAXN], pre[MAXN], suf[MAXN];
using pt = pair < int, int>;

signed main() {
    ios::sync_with_stdio(false);
    int n;cin >> n;
    for (int i = 0;i < n;++i)cin >> nums[i];
    int ans = 0, cut = 0;
    for (int i = n - 1;i >= 0;--i)
        suf[i] = cut = min(cut + 1, nums[i]);
    cut = 0;
    for (int i = 0;i < n;++i) {
        pre[i] = cut = min(cut + 1, nums[i]);
        ans = max(ans, min(suf[i], pre[i]));
    }
    cout << ans;

    return 0;
}