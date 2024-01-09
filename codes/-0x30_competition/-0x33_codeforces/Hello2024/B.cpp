#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int MAXN = 6e6, mod = 1e9 + 7;
int nums[MAXN], v[MAXN];

void solve() {
    int n;cin >> n;
    char tmp;
    int a, b;a = b = 0;
    for (int i = 0;i < n;++i) {
        cin >> tmp;
        if (tmp == '+')a++;
        if (tmp == '-')b++;
    }
    cout << abs(a - b);
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