#include<bits/stdc++.h>
#define int long long 
using namespace std;
constexpr int MAXN = 1e6;
int nums[MAXN];
using pt = pair < int, int>;

signed main() {
    ios::sync_with_stdio(false);
    int n;cin >> n;
    int ans = 0;
    while (n) {
        int t = 1, tmp = 1;
        while (t * 5 < n)t *= 5, tmp *= 10;
        ans += tmp;
        n -= t;
    }
    cout << (ans - 1) * 2;
    return 0;
}