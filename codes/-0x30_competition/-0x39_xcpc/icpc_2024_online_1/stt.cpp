#include<bits/stdc++.h>

const int MAXN = 1e6 + 10;
const int N = 1e6;

struct Info
{
    Info operator+(const Info& x) {

    }
}tree[MAXN << 2];

int n;
void update(int p, Info& x, int l = 1, int r = n, int i = 1) {
    if (l > r)return;
    if (p < l || r < p)return;
    if (l == r) {
        tree[i] = x;
        return;
    }
    int mid = l + r >> 1;
    update(p, x, l, mid, i << 1);
    update(p, x, mid + 1, r, i << 1 | 1);
    tree[i] = tree[i << 1] + tree[i << 1 | 1];
}

Info query(int ql, int qr, int l = 1, int r = n, int i = 1) {
    if (l > r)return Info();
    if (qr < l || r < ql)return Info();
    if (ql <= l && r <= qr) {
        return tree[i];
    }
    int mid = l + r >> 1;
    return query(ql, qr, l, mid, 1 << 1) + query(ql, qr, mid + 1, r, i << 1 | 1);
}

void solve() {

}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t = 1;std::cin >> t;
    while (t--) {
        solve();
        std::cout << '\n';
    }
    return 0;
}