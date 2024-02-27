#include <bits/stdc++.h>
#define int long long 
using namespace std;
constexpr int MAXN = 1e5 + 10, mod = 1e9 + 7;
using pt = pair<int, int>;
int nums[MAXN];

signed main() {
    ios::sync_with_stdio(false);
    char tmp;cin >> tmp >> tmp;
    int x;cin >> x;
    string s;cin >> s;
    int win = (x + 1) / 2;
    int r = 0, p = 0, cnt = 0;
    for (char ch : s) {
        if (ch == 'R')r++;
        if (ch == 'P')p++;
        cnt++;
        if (r == win) {
            cout << "kou!" << '\n';
            cout << cnt << '\n';
            return 0;
        }
        if (p == win) {
            cout << "yukari!" << '\n';
            cout << cnt << '\n';
            return 0;
        }
    }
    cout << "to be continued." << '\n';
    cout << cnt << '\n';
    return 0;
}