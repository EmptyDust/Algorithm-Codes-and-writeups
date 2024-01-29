#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int MAXN = 1e6 + 100;
#define l first
#define r second
#define lt(x) (x<<1)
#define rt(x) (x<<1)|1
int tree[MAXN * 4], nums[MAXN * 2], n = 0, zbs[MAXN * 2], lazy[MAXN * 4];

using pt = pair<int, int>;
pt pts[MAXN];int ops[MAXN];

void update(int ql, int qr, int x, int l = 1, int r = n, int i = 1) {
    if (l > r)return;
    if (qr < l || r < ql)return;
    if (l == r) {
        tree[i] += x;
        return;
    }
    int mid = l + r >> 1;
    update(ql, qr, x, l, mid, lt(i));
    update(ql, qr, x, mid + 1, r, rt(i));
    tree[i] = max(tree[lt(i)], tree[rt(i)]);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int q;cin >> q;
    for (int i = 0;i < q;++i) {
        char op;cin >> op;
        ops[i] = (op == '+' ? 1 : -1);
        cin >> pts[i].l >> pts[i].r;
        nums[n++] = pts[i].l;
        nums[n++] = pts[i].r;
    }
    iota(zbs, zbs + n, 0);
    sort(zbs, zbs + n, [&](int a, int b) {return nums[a] < nums[b];});
    map<int, int> mp;
    for (int i = 0;i < n;++i)mp[nums[zbs[i]]] = i + 1;
    for (int i = 0;i < q;++i) {
        update(mp[pts[i].l], mp[pts[i].r], ops[i]);
        cout << (tree[1] > 1 ? "Yes" : "No") << '\n';
    }
    return 0;
}