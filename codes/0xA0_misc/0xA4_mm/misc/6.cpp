#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll inf = 0x3f3f3f3f3f3f3f3fLL;
const int infi = 0x3f3f3f3f;

struct {
    int left, right, val;
} seg[10000000];
int tot;

void update(int& x, int l, int r, int p) {
    if (!x) x = ++tot;
    seg[x].val++;
    if (l == r) return;
    int mid = l + (r - l) / 2;
    if (p <= mid) update(seg[x].left, l, mid, p);
    else update(seg[x].right, mid + 1, r, p);
}

int query(int x, int l, int r, int s, int t) {
    if (!x) return 0;
    if (s <= l && r <= t) return seg[x].val;
    int mid = l + (r - l) / 2;
    int ans = 0;
    if (s <= mid) ans += query(seg[x].left, l, mid, s, t);
    if (t > mid) ans += query(seg[x].right, mid + 1, r, s, t);
    return ans;
}

int merge(int x, int y) {
    if (!x || !y) return x | y;
    seg[x].val += seg[y].val;
    seg[x].left = merge(seg[x].left, seg[y].left);
    seg[x].right = merge(seg[x].right, seg[y].right);
    return x;
}

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector<pair<int, int>> e(m + 1);
    for (int i = 1; i <= m; i++) cin >> e[i].first >> e[i].second;
    vector<int> d(m + 1);
    vector<array<int, 3>> op(q + 1);
    for (int i = 1; i <= q; i++) {
        auto& [x, y, z] = op[i];
        cin >> x;
        if (x == 1) {
            cin >> y;
            d[y]++;
        }
        else {
            cin >> y >> z;
        }
    }

    vector<int> k(a);
    sort(k.begin() + 1, k.end());
    k.erase(unique(k.begin() + 1, k.end()), k.end());
    auto index = [&](int x) -> int {
        return lower_bound(k.begin() + 1, k.end(), x) - k.begin();
        };
    vector<int> root(n + 1), rootseg(n + 1);
    iota(root.begin() + 1, root.end(), 1);
    for (int i = 1; i <= n; i++) {
        root[i] = i;
        update(rootseg[i], 1, k.size() - 1, index(a[i]));
    }
    function<int(int)> find = [&](int u) -> int {
        if (root[u] != u) root[u] = find(root[u]);
        return root[u];
        };
    auto add = [&](int u, int v) -> void {
        u = find(u);
        v = find(v);
        if (u == v) return;
        root[u] = v;
        rootseg[v] = merge(rootseg[v], rootseg[u]);
        };
    for (int i = 1; i <= m; i++) {
        if (!d[i]) add(e[i].first, e[i].second);
    }
    vector<int> ans(q + 1);
    int cnt = 0;
    for (int i = q; i > 0; i--) {
        auto [x, y, z] = op[i];
        if (x == 1) {
            if (--d[y] == 0) add(e[y].first, e[y].second);
        }
        else {
            auto it = upper_bound(k.begin() + 1, k.end(), z - a[y]);
            if (it != k.begin()) {
                it--;
                ans[i] = query(rootseg[find(y)], 1, k.size() - 1, 1, it - k.begin());
            }
            cnt++;
            if (a[y] * 2 <= z) ans[i]--;
        }
    }
    for (int i = 1; i <= q; i++) {
        if (op[i][0] == 2) {
            cout << ans[i] << endl;
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t = 1;
    //cin >> t;

    while (t--) {
        solve();
    }
}