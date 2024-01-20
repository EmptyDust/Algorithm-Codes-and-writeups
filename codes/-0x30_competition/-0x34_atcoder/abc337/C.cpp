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
    int f;
    for (int i = 0;i < n;++i) {
        int tmp;cin >> tmp;
        tmp--;
        if (tmp == -2)f = i;
        else nums[tmp] = i;
    }
    for (int i = 0;i < n;++i) {
        cout << f + 1 << ' ';
        f = nums[f];
    }
    return 0;
}