#include <bits/stdc++.h>
#define int long long
#define num first 
#define cnt second 
using namespace std;
constexpr int MAXN = 2e6;
using pt = pair<int, int>;
int nums[MAXN];
int stk[MAXN], cnts[MAXN], ski = 0, skj = -1;

signed main() {
    ios::sync_with_stdio(false);
    int n;cin >> n;
    for (int i = 0;i < n;++i)cin >> nums[i];
    sort(nums, nums + n);
    for (int i = 0;i < n;++i) {
        if (i > 0 && nums[i] != nums[i - 1])
            skj = ski - 1;
        if (skj < 0 || stk[skj] + 1 != nums[i]) {
            stk[ski] = nums[i];
            cnts[ski] = 1;
            ski++;
            continue;
        }
        stk[skj]++;
        cnts[skj]++;
        skj--;
    }
    int ret = INT_MAX;
    for (int i = 0;i < ski;++i) {
        ret = min(ret, cnts[i]);
    }

    cout << ret;
    return 0;
}