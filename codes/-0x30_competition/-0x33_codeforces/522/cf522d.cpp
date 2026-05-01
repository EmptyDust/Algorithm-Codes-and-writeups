#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 5e5, MAXN = 5e5 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;
using a3 = std::array<int, 3>;
//找最小值 每个值加上n-i
int smt[MAXN * 4], n, m;
void update(int p, int x, int l = 1, int r = n, int i = 1) {
    if (l > r)return;
    if (r < p || p < l)return;
    if (l == r) {
        smt[i] = x;
        return;
    }
    int mid = l + r >> 1;
    update(p, x, l, mid, i << 1);
    update(p, x, mid + 1, r, i << 1 | 1);
    smt[i] = std::min(smt[i << 1], smt[i << 1 | 1]);
}

int query(int ql, int qr, int l = 1, int r = n, int i = 1) {
    if (l > r)return inf;
    if (r < ql || qr < l)return inf;
    if (ql <= l && r <= qr) {
        return smt[i];
    }
    int mid = l + r >> 1;
    int x = query(ql, qr, l, mid, i << 1);
    int y = query(ql, qr, mid + 1, r, i << 1 | 1);
    return std::min(x, y);
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n >> m;
    std::vector<int> a(n + 1), b(n + 1, -1);
    std::map<int, int> mp;
    for (int i = 1;i <= n;++i)std::cin >> a[i];
    for (int i = 1;i <= n;++i) {
        if (mp.count(a[i]))update(i, i - mp[a[i]]), b[mp[a[i]]] = i;
        else update(i, inf);
        mp[a[i]] = i;
    }
    std::vector<a3> pts(m);
    std::vector<int> ans(m);
    int idx = 0;
    for (auto& [l, r, i] : pts)std::cin >> l >> r, i = idx++;
    std::sort(pts.begin(), pts.end());
    int x = 0;
    for (auto& [l, r, ansi] : pts) {
        while (x < l) {
            if (b[x] != -1) {
                update(b[x], inf);
            }
            x++;
        }
        ans[ansi] = query(l, r);
    }
    for (auto& x : ans)std::cout << (x == inf ? -1 : x) << '\n';
    return 0;
}