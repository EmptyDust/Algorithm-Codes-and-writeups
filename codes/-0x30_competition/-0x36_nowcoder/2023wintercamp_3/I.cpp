#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int MAXN = 1e6 + 10;
int nums[MAXN], n;
using pt = pair<int, int>;

signed main() {
    ios::sync_with_stdio(false);
    int k, n;cin >> k >> n;
    string s; cin >> s;
    cout << s << endl;
    int sum = 0;
    for (char ch : s) {
        sum += ch - 'a';
    }
    cout << sum << endl;
    int y = sum % 23;
    int t = y * 23 / __gcd(y, (int)23);
    cout << t;
    return 0;
}