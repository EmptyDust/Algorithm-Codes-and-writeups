#include <bits/stdc++.h>
#define int long long 
using namespace std;
constexpr int MAXN = 1e6;
int nums[MAXN];
using pt = pair<int, int>;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int a, b, d;cin >> a >> b >> d;
    if (a == b) {
        cout << a;
        return 0;
    }
    int t = (b - a) / (d + 1);
    for (int i = a;i <= b;i += d) {
        cout << i << ' ';
    }
    return 0;
}