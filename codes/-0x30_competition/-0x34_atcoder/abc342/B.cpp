#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int MAXN = 1e6 + 10;
int nums[MAXN], n;
using pt = pair<int, int>;

signed main() {
    ios::sync_with_stdio(false);
    int n;cin >> n;
    map<int, int> mp;
    for (int i = 0;i < n;++i) {
        cin >> nums[i];
        mp[nums[i]] = i;
    }
    int q;cin >> q;
    while (q--) {
        int m, n;
        cin >> m >> n;
        cout << (mp[m] > mp[n] ? n : m) << '\n';
    }
    return 0;
}