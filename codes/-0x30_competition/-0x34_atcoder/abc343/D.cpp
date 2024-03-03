#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int MAXN = 1e6 + 10;
int nums[MAXN], n;
using pt = pair<int, int>;

signed main() {
    ios::sync_with_stdio(false);
    int n, t;cin >> n >> t;
    map<int, int> mp;
    mp[0] = n;
    int ans = 1;
    while (t--) {
        int a, b;cin >> a >> b;
        mp[nums[a]]--;
        if (mp[nums[a]] == 0)ans--;
        nums[a] += b;
        if (mp[nums[a]] == 0)ans++;
        mp[nums[a]]++;
        cout << ans << endl;
    }
    return 0;
}