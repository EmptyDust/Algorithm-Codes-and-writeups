#include <bits/stdc++.h>
#define int long long 
using namespace std;
constexpr int MAXN = 1e6, mod = 1e9 + 7;
int nums[MAXN];
using pt = pair<int, int>;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n;cin >> n;
    string s;
    map<int, int> mp;
    for (int i = 0;i < n;++i) {
        cin >> s;
        int num = 0;
        for (char ch : s)num = (num * 10 + ch - '0') % mod;
        mp[num]++;
    }
    int ans = 0;
    for (auto [a, acnt] : mp)for (auto [b, bcnt] : mp)
        if (mp.count(a * b % mod))
            ans += acnt * bcnt * mp[a * b % mod];
    cout << ans;
    return 0;
}