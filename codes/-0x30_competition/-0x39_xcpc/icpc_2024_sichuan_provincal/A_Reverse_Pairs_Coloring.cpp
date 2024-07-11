#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 3e5, MAXN = 3e5 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;

struct Info
{
    bool all = 1, l = 1, r = 1;
    int cnt = 0;
    Info operator+ (const Info& info) {
        if (all && info.all)return { 1,1,1,0 };
        if (all) return { 0,1,info.r,info.cnt };
        if (info.all)return { 0,l,1,cnt };
        if (!r && !info.l)return { 0,l,info.r,cnt + info.cnt };
        return { 0,l,info.r,cnt + info.cnt + 1 };
    }
}tree[MAXN << 2];

int n;
void update(int p, bool x, int l = 1, int r = n, int i = 1) {
    if (l > r)return;
    if (l > p || p > r)return;
    if (l == r) {
        tree[i] = { !x,!x,!x,0 };
        return;
    }
    int mid = l + r >> 1;
    update(p, x, l, mid, i << 1);
    update(p, x, mid + 1, r, i << 1 | 1);
    tree[i] = tree[i << 1] + tree[i << 1 | 1];
}

Info query(int ql, int qr, int l = 1, int r = n, int i = 1) {
    if (l > r)return Info();
    if (l > qr || ql > r)return Info();
    if (ql <= l && r <= qr) {
        return tree[i];
    }
    int mid = l + r >> 1;
    Info ret = query(ql, qr, l, mid, i << 1) + query(ql, qr, mid + 1, r, i << 1 | 1);
    return ret;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n;
    std::vector<int> a(n);
    for (int& x : a)std::cin >> x;
    i64 ans = 0;
    for (int i = 0;i < n;++i) {
        update(a[i], 1);
        if (i == 0) {
            if (a[i] != 1)ans++;
            continue;
        }
        if (a[i] > a[i - 1]) {
            ans += query(a[i - 1], a[i]).cnt;
        }
    }
    std::cout << ans;
    return 0;
}