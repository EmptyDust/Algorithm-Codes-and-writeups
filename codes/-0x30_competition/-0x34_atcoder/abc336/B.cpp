#include<bits/stdc++.h>
#define int long long 
using namespace std;
constexpr int MAXN = 1e6;
int nums[MAXN];
using pt = pair < int, int>;

signed main() {
    ios::sync_with_stdio(false);
    int n, ans = 0;
    cin >> n;
    while (n) {
        if (n & 1)break;
        ans++;
        n >>= 1;
    }
    cout << ans;
    return 0;
}