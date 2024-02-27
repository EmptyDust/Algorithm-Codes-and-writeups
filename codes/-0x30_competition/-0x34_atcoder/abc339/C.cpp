#include <bits/stdc++.h>
#define int long long 
using namespace std;
constexpr int MAXN = 1e6;
int nums[MAXN];
using pt = pair<int, int>;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n;cin >> n;
    int sum = 0, m = 0;
    for (int i = 0;i < n;++i) {
        cin >> nums[i];
        sum += nums[i];
        m = min(m, sum);
    }
    cout << abs(m) + sum;
    return 0;
}