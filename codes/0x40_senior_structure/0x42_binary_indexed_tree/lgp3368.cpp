#include <bits/stdc++.h>
using namespace std;
#define lowbit(x) x&-x
constexpr int MAXN = 5e5 + 100;
int n, m, nums[MAXN], mi[MAXN], i_tree[MAXN];

void update(int x, int num) {
    for (int i = x;i <= n;i += lowbit(i))
        i_tree[i] += num;
}

void print(int x) {
    int ans = 0;
    for (int i = x;i;i -= lowbit(i))
        ans += i_tree[i];
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1;i <= n;++i)cin >> nums[i];
    for (int i = 1;i <= n;++i)mi[i] = nums[i] - nums[i - 1];
    for (int i = 1;i <= n;++i)update(i, mi[i]);
    int op, x, y, k;
    while (m--) {
        cin >> op;
        if (op == 1) {
            cin >> x >> y >> k;
            update(x, k);
            update(y + 1, -k);
        }
        else {
            cin >> x;
            print(x);
        }
    }
    return 0;
}