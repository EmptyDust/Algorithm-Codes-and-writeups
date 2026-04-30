#include <bits/stdc++.h>
#define int long long 
using namespace std;
constexpr int MAXN = 1e6 + 10;
int nums[MAXN], n;
using pt = pair<int, int>;

bool solve() {
    int k, x, a;cin >> k >> x >> a;
    int sum = 0, cur;
    for (int i = 0;i <= x;++i) {
        cur = sum / (k - 1) + 1;
        sum += cur;
        //cout << cur << ' ';
        if (sum > a)return false;
    }
    return sum <= a;
}

signed main() {
    ios::sync_with_stdio(false);
    int t;cin >> t;
    while (t--) {
        cout << (solve() ? "YES" : "NO");
        cout << '\n';
    }
    return 0;
}