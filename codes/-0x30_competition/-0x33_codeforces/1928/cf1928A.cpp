#include <bits/stdc++.h>
#define int long long 
using namespace std;
constexpr int MAXN = 1e6 + 10;
int nums[MAXN], n;
using pt = pair<int, int>;

void solve() {
    int a, b;cin >> a >> b;
    if (a % 2 == 0 && b % 2 == 0) {
        cout << "Yes";
        return;
    }
    if (a % 2 == 1 && b % 2 == 1) {
        cout << "No";
        return;
    }
    if (a > b)swap(a, b);
    cout << (2 * a == b ? "No" : "Yes");
}

signed main() {
    ios::sync_with_stdio(false);
    int t;cin >> t;
    while (t--) {
        solve();
        cout << '\n';
    }
    return 0;
}