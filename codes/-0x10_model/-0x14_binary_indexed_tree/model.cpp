#include <bits/stdc++.h>
#define int long long
#define lowbit(x) (x&(-x))
using namespace std;
constexpr int MAXN = 1e6;
int nums[MAXN], n, m, tmp, op, x, k, ans;

signed main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1;i <= n;++i) {
        cin >> tmp;
        for (int j = i; j <= n;j += lowbit(j))
            nums[j] += tmp;
    }
    while (m--) {
        cin >> op >> x >> k;
        if (op == 1) {
            for (int j = x;j <= n;j += lowbit(j))
                nums[j] += k;
        }
        if (op == 2) {
            ans = 0;
            for (int j = x - 1;j > 0;j -= lowbit(j))
                ans -= nums[j];
            for (int j = k;j > 0;j -= lowbit(j))
                ans += nums[j];
            cout << ans << '\n';
        }
    }
    return 0;
}
