#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int MAXN = 1e6 + 10;
int nums[MAXN], n;
using pt = pair<int, int>;

void solve() {
    int n;cin >> n;
    if (n == 1) {
        int x, y, z;
        cin >> x >> y >> z;
        if (x == y && z == 1)cout << "No";
        else cout << "Yes";
    }
    else {
        int x1, y1, z1, x2, y2, z2;
        cin >> x1 >> y1 >> z1;
        cin >> x2 >> y2 >> z2;
        if (x1 == y1 && z1 == 1) {
            cout << "No";return;
        }
        if (x2 == y2 && z2 == 1) {
            cout << "No";return;
        }
        if (x1 == x2 && y1 == y2) {
            if (z1 == z2)cout << "Yes";
            else cout << "No";
        }
        else if (x1 == y2 && x2 == y1) {
            if (z1 == z2) {
                if (z1 == 0)cout << "Yes";
                else cout << "No";
            }
            else cout << "Yes";
        }
        else cout << "Yes";
    }
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