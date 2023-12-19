#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int MAXN = 1e6;
constexpr int mod = 1e9 + 7;
using pt = pair<int, int>;
int n2[32] = { 0 };
bool bn2[32] = { 0 };

signed main() {
    ios::sync_with_stdio(false);
    int t, op, x;cin >> t;
    while (t--) {
        cin >> op >> x;
        if (op == 1) {
            n2[x]++;
        }
        else {
            bool f = true;
            int cnt = 0;
            for (int i = 0;i <= 30;++i) {
                if ((x >> i) & 1) {
                    if (n2[i] || cnt > 0) {
                        cnt = (cnt + n2[i] - 1) / 2;
                        continue;
                    }
                    f = false;
                    break;
                }
                else
                    cnt = (cnt + n2[i]) / 2;
            }
            cout << (f ? "YES" : "NO") << '\n';
        }
    }
    return 0;
}