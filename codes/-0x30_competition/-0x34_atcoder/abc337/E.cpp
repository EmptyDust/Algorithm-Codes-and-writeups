#include <bits/stdc++.h>
#define int long long 
using namespace std;
constexpr int MAXN = 1e6;
int nums[MAXN], ans[MAXN];
using pt = pair<int, int>;

signed main() {
    int n;cin >> n;
    int m = ceil(log2(n));
    cout << m << endl;
    for (int i = 0;i < m;++i) {
        int ani = 0;
        for (int j = 0;j < n;++j) {
            if ((j >> i) & 1)
                ans[ani++] = j;
        }
        cout << ani << ' ';
        for (int k = 0;k < ani;++k)cout << ans[k] << ' ';
        cout << endl;
    }
    string s;cin >> s;
    int t = 1, ret = 0;
    for (char ch : s) {
        if (ch == '1')ret += t;
        t <<= 1;
    }
    cout << (ret == 0 ? n : ret);

    return 0;
}