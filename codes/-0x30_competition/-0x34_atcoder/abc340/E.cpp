#include <bits/stdc++.h>
#define int long long 
using namespace std;
constexpr int MAXN = 1e6;
int nums[MAXN], qry[MAXN], m_tree[MAXN], n, m, ans[MAXN];
#define lowbit(x) x&-x
using pt = pair<int, int>;

void update(int pos, int x) {
    for (int i = pos;i <= n;i += lowbit(i))
        m_tree[i] += x;
}

int qynum(int pos) {
    int ret = ans[pos];
    for (int i = pos;i > 0;i -= lowbit(i))
        ret += m_tree[i];
    return ret;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1;i <= n;++i) {
        cin >> nums[i];
        update(i, nums[i] - nums[i - 1]);
    }
    for (int i = 1;i <= m;++i) {
        cin >> qry[i];
        int q = qry[i] + 1;
        int num = qynum(q);
        ans[q] -= num;
        int a = num / n, b = num % n;
        update(1, a);
        update(q + 1, 1);
        if (q + 1 + b <= n)
            update(q + 1 + b, -1);
        else {
            update(1, 1);
            update(q + 1 + b - n, -1);
        }
    }
    for (int i = 1;i <= n;++i) {
        cout << qynum(i) << ' ';
    }
    return 0;
}