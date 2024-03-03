#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int MAXN = 1e6 + 10;
int nums[MAXN], cntl[MAXN], cntr[MAXN], n;
using pt = pair<int, int>;

void solve() {
    cin >> n;
    string s;cin >> s;
    for (int i = 0;i < n;++i)nums[i] = s[i] == '>';
    int tmp = 0, sum = 0;
    for (int i = 0;i < n;++i) {
        cntl[i] = tmp += nums[i];

    }
    tmp = 0;
    for (int i = n - 1;~i;--i)cntr[i] = tmp += !nums[i];

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