#include<bits/stdc++.h>
using namespace std;
#define int long long
int nums[1010] = { 0 };
int solve(int n) {
    int res = nums[1], tmp = nums[1];
    for (int i = 2;i <= n;i++) {
        tmp = std::max(nums[i], nums[i] + tmp);
        res = std::max(res, tmp);
    }
    return res;
}
void swap(int i, int j) {
    int tmp = nums[i];
    nums[i] = nums[j];
    nums[j] = tmp;
}
signed main() {
    int n, k, res;
    cin >> n >> k;
    for (int i = 1;i <= n;i++) cin >> nums[i];
    res = solve(n);
    if (k) {
        for (int i = 2;i <= n;i++) {
            swap(i, i - 1);
            res = std::max(solve(n), res);
            swap(i, i - 1);
        }
    }
    cout << res << endl;
    return 0;
}