#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e5 + 100, MAXN = 1e5 + 1000, inf = 1e9, mod = 1e9 + 7;
int tree[MAXN * 4], max[MAXN * 4], xcnt[MAXN], ycnt[MAXN], n, r;
std::map<int, int> adj[MAXN];
using pt = std::pair<int, int>;

void update(int x, int pos, int l = 1, int r = N, int i = 1) {
    if (l > r)return;
    if (pos < l || r < pos)return;
    if (l == r) {
        tree[i] += x;
        max[i] = tree[i];
        return;
    }
    int mid = l + r >> 1;
    update(x, pos, l, mid, i * 2);
    update(x, pos, mid + 1, r, i * 2 + 1);
    max[i] = std::max(max[i * 2], max[i * 2 + 1]);
}

void query(int pos, int l = 1, int r = N, int i = 1) {
    if (l > r)return;
    if (pos < l || r < pos)return;
    if (l == r) {
        std::cout << tree[i] << ' ';
        return;
    }
    int mid = l + r >> 1;
    query(pos, l, mid, i * 2);
    query(pos, mid + 1, r, i * 2 + 1);
}

/*
建树 按y放入 遍历x
*/

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n >> r;
    std::vector<pt> pts(n);
    for (auto& [x, y] : pts) {
        std::cin >> x >> y;
        x++, y++;
        xcnt[x]++;
        ycnt[y]++;
        adj[x][y]++;
    }
    for (int i = 1;i <= N;++i) {
        update(ycnt[i], i);
        if (i + r <= N)
            update(ycnt[i + r], i);
        if (i + 2 * r <= N)
            update(ycnt[i + 2 * r], i);
    }
    //for (int i = 1;i <= 8;++i)query(i);std::cout << '\n';
    int res = 0, cur = 0;
    for (int i = 1;i <= r;++i) {
        int pre1 = -1, pre2 = -1, pre3 = -1;
        for (int x = i;x <= N;x += r) {
            for (auto& [y, cnt] : adj[x]) {
                cur += cnt;
                update(-cnt, y);
                if (y - r > 0)
                    update(-cnt, y - r);
                if (y - 2 * r > 0)
                    update(-cnt, y - 2 * r);
            }

            if (pre3 > 0) {
                for (auto& [y, cnt] : adj[pre3]) {
                    cur -= cnt;
                    update(cnt, y);
                    if (y - r > 0)
                        update(cnt, y - r);
                    if (y - 2 * r > 0)
                        update(cnt, y - 2 * r);
                }
            }
            res = std::max(res, max[1] + cur);

            pre3 = pre2;
            pre2 = pre1;
            pre1 = x;
        }
        if (~pre1) {
            for (auto& [y, cnt] : adj[pre1]) {
                cur -= cnt;
                update(cnt, y);
                if (y - r > 0)
                    update(cnt, y - r);
                if (y - 2 * r > 0)
                    update(cnt, y - 2 * r);
            }
        }
        if (~pre2) {
            for (auto& [y, cnt] : adj[pre2]) {
                cur -= cnt;
                update(cnt, y);
                if (y - r > 0)
                    update(cnt, y - r);
                if (y - 2 * r > 0)
                    update(cnt, y - 2 * r);
            }
        }
        if (~pre3) {
            for (auto& [y, cnt] : adj[pre3]) {
                cur -= cnt;
                update(cnt, y);
                if (y - r > 0)
                    update(cnt, y - r);
                if (y - 2 * r > 0)
                    update(cnt, y - 2 * r);
            }
        }
    }
    //for (int i = 1;i <= 8;++i)query(i);
    std::cout << res;
    return 0;
}