#include <bits/stdc++.h>
#define int long long 
using namespace std;
constexpr int MAXN = 1e6 + 10;
int nums[MAXN], a[MAXN], b[MAXN];
using pt = pair<int, int>;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n;cin >> n;
    for (int i = 0;i < n;++i)cin >> nums[i];
    for (int i = 0;i < n;++i)cin >> a[i] >> b[i];
    for (int i = 0;i < n - 1;++i) {
        nums[i + 1] += nums[i] / a[i] * b[i];
    }
    cout << nums[n - 1];
    return 0;
}