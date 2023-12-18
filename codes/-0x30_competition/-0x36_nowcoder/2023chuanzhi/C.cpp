#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int MAXN = 1e6;
int nums[MAXN];
constexpr int MOD = 1e9 + 7;
int mpow(int x, int n) {
    if (n == 1)return x % MOD;
    int tmp = mpow(x, n / 2) % MOD;
    if (n & 1)return (tmp * tmp) % MOD * x % MOD;
    return (tmp * tmp) % MOD;
}

signed main() {
    ios::sync_with_stdio(false);
    string s;cin >> s;
    int chs[26] = { 0 };
    char mx = 'a', mn = 'z';
    for (char ch : s) {
        if (ch > mx)mx = ch;
        if (ch < mn)mn = ch;
        chs[ch - 'a']++;
    }
    int cnt = 0;
    vector<int> mp;
    for (int i = 0;i < 26;++i) {
        if (chs[i] != 0)
            mp.push_back(i);
    }
    int ans = mpow(25, s.length());
    /*int t = 0;
    for (int i = 0;i < 26;++i) if (chs[i] == 0) {
        bool f = true;
        for (int j = 1;j < mp.size();++j) {
            if (i + mp[j] - mp[j - 1] >= 26 || i + mp[j] - mp[j - 1] < 0 || chs[i + mp[j] - mp[j - 1]] != 0) {
                f = false;
                break;
            }
        }
        if (f)t++;
    }*/
    ans += MOD - (25 - (mx - mn));
    cout << ans % MOD;
    return 0;
}