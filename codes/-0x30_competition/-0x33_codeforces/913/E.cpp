#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n;cin >> n;
    int nums[10] = { 1,3,6,10,15,21,28,36,45,55 };
    while (n--) {
        int tmp;
        cin >> tmp;
        int ans = 1;
        while (tmp) {
            ans *= nums[tmp % 10];
            tmp /= 10;
        }
        cout << ans << '\n';
    }
    return 0;
}