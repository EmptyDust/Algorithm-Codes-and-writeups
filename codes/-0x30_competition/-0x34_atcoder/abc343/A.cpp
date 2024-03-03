#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int MAXN = 1e6 + 10;
int nums[MAXN], n;
using pt = pair<int, int>;

signed main() {
    ios::sync_with_stdio(false);
    int a, b;cin >> a >> b;
    if (a + b == 1)cout << 0;
    else cout << 1;
    return 0;
}