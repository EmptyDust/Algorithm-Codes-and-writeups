#include <bits/stdc++.h>
#define int long long
#define MAXN 1000000
using namespace std;

#define ls(i) i<<1
#define rs(i) (i<<1)|1

int nums[MAXN], tree[4 * MAXN], lazy[4 * MAXN];

int set_up(int l, int r, int i = 1) {
    lazy[i] = 0;
    if (l == r)
        return tree[i] = nums[l];
    int mid = l + r >> 1;
    return tree[i] = set_up(l, mid, ls(i)) + set_up(mid + 1, r, rs(i));
}

inline void push_down(int i, int l, int r) {
    int mid = l + r >> 1;
    lazy[ls(i)] += lazy[i];
    lazy[rs(i)] += lazy[i];
    tree[ls(i)] += lazy[i] * (mid - l + 1);
    tree[rs(i)] += lazy[i] * (r - mid);
    lazy[i] = 0;
}

void update(int l, int r, int ql, int qr, int d, int i = 1) {
    if (ql > r || qr < l)
        return;
    if (ql <= l && r <= qr) {
        tree[i] += (r - l + 1) * d;
        if (l < r)
            lazy[i] += d;
    }
    else {
        int mid = l + r >> 1;
        push_down(i, l, r);
        update(l, mid, ql, qr, d, ls(i));
        update(mid + 1, r, ql, qr, d, rs(i));
        tree[i] = tree[ls(i)] + tree[rs(i)];
    }
}

int query(int l, int r, int ql, int qr, int i = 1) {
    if (ql > r || qr < l)
        return 0;
    if (ql <= l && r <= qr)
        return tree[i];
    else {
        int mid = l + r >> 1;
        push_down(i, l, r);
        return query(l, mid, ql, qr, ls(i)) + query(mid + 1, r, ql, qr, rs(i));
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1;i <= n;++i)cin >> nums[i];
    set_up(1, n);
    while (m--) {
        int t, x, y;
        cin >> t >> x >> y;
        if (x > y)swap(x, y);
        if (t == 1) {
            int k;cin >> k;
            update(1, n, x, y, k);
        }
        else
            cout << query(1, n, x, y) << '\n';
    }
    return 0;
}