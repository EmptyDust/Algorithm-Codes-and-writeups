#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int MAXN = 1e6, mod = 1e9 + 7;
int n, nums[MAXN];

using pt = pair<int, int>;

void solve() {
    int n, k;cin >> k >> n;
    while (k--)for (int i = 0;i < n;++i)cout << (char)('a' + i);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t;cin >> t;
    while (t--)solve(), cout << '\n';
    return 0;
}