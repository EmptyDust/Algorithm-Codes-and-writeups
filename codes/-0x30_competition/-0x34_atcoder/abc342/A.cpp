#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int MAXN = 1e6 + 10;
int nums[MAXN], n;
using pt = pair<int, int>;

signed main() {
    ios::sync_with_stdio(false);
    string s;
    map<char, int> mp;
    cin >> s;
    char ans;
    for (char ch : s) {
        mp[ch]++;
    }
    for (auto [ch, cnt] : mp) {
        if (cnt == 1)ans = ch;
    }
    for (int i = 0;i < s.length();++i)if (s[i] == ans)cout << i + 1;
    return 0;
}