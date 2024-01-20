#include<bits/stdc++.h>
#define int long long 
using namespace std;
constexpr int MAXN = 1e6;
int nums[MAXN];
using pt = pair < int, int>;

signed main() {
    ios::sync_with_stdio(false);
    int n;cin >> n;
    int cnt = 0, cnt2 = 0;
    for (int i = 1;i <= n;++i) {
        int tmp = i, sum = 0;
        while (tmp) {
            sum += tmp % 10;
            tmp /= 10;
        }
        if (sum != 2)continue;
        if (i % 8 == 4)cout << i << endl;
    }
    return 0;
}