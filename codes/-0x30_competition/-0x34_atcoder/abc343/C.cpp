#include <bits/stdc++.h>
#define int long long
using namespace std;
using pt = pair<int, int>;

signed main() {
    ios::sync_with_stdio(false);
    int n;cin >> n;
    int ans = 1;
    for (int x = 1;x * x * x <= n;++x) {
        int num = x * x * x;
        string s = to_string(num);
        string re = s;
        reverse(s.begin(), s.end());
        if (s == re && num <= n) {
            ans = num;
        }
    }
    cout << ans;
    return 0;
}