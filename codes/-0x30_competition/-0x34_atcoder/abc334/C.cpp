#include <bits/stdc++.h>
#define int long long
#define ll long long
using namespace std;
constexpr int MAXN = 5e6 + 10;
int nums[MAXN], suml[MAXN], sumr[MAXN];
int n, k;
signed main() {
    ios::sync_with_stdio(false);
    cin >> n >> k;
    if (k == 1) { cout << 0;return 0; }
    for (int i = 0;i < k;++i)cin >> nums[i];
    sort(nums, nums + k);
    for (int i = 0;i < k - 1;i += 2) {
        suml[i] = nums[i + 1] - nums[i];
        if (i >= 2)suml[i] += suml[i - 2];
    }
    for (int i = k - 2;i >= 0;i -= 2) {
        sumr[i] = nums[i + 1] - nums[i];
        if (i <= k - 4)sumr[i] += sumr[i + 2];
    }
    if (k & 1) {
        int ans = min(suml[k - 3], sumr[1]);
        for (int i = 2;i <= k - 3;i += 2) {
            ans = min(ans, suml[i - 2] + sumr[i + 1]);
        }
        cout << ans;
    }
    else cout << suml[k - 2];

    return 0;
}