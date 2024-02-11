#include <bits/stdc++.h>
#define int long long 
using namespace std;
constexpr int MAXN = 1e6;
int nums[MAXN];
using pt = pair<int, int>;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    map<char, int> mp;
    char ans;int mx = 0;
    string s;cin >> s;
    for (char ch : s) {
        mp[ch]++;
        if (mp[ch] > mx) {
            mx = mp[ch];
            ans = ch;
        }
        else if (mp[ch] == mx && ans > ch) {
            ans = ch;
        }
    }
    cout << ans;
    return 0;
}