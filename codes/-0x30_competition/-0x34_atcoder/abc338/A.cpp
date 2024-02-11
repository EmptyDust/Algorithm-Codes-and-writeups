#include <bits/stdc++.h>
#define int long long 
using namespace std;
constexpr int MAXN = 1e6;
int nums[MAXN];
using pt = pair<int, int>;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    string s;cin >> s;
    bool f = true;
    if (!isupper(s[0]))f = false;
    for (int i = 1;i < s.length();++i)if (!islower(s[i]))f = false;
    cout << (f ? "Yes" : "No");
    return 0;
}