#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int MAXN = 1e6 + 10;
int nums[MAXN], n;
using pt = pair<int, int>;

void solve() {
    string s1, s2;
    cin >> s1 >> s2;
    if (s1.at(0) == s2.at(0) || abs(s1.at(0) - s2.at(0)) == 22)
        cout << "Yes";
    else  cout << "No";
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