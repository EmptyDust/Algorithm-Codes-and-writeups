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
    bool a, b, c;
    a = b = c = true;
    for (char ch : s) {
        if (a && ch == 'A')continue;
        if (b && ch == 'B') {
            a = false;
            continue;
        }
        if (c && ch == 'C') {
            a = false;
            b = false;
            continue;
        }
        cout << "No";
        return 0;
    }
    cout << "Yes";
    return 0;
}