#include <bits/stdc++.h>

using i64 = long long;

const int MAXN = 2e5 + 10;
using pii = std::pair<int, int>;
using a3 = std::array<int, 3>;
std::string s;
std::vector<i64> b;

struct Info {
    std::vector<int> pos;
    Info() { pos.assign(26, -1); }
    Info(char ch, int i) {
        pos.assign(26, -1);
        pos[ch - 'a'] = i;
        // std::cout << pos[0];
    }
    Info operator+(const Info& x) {
        Info res = Info();
        std::vector<a3> d;
        std::vector<pii> rs;
        for (int i = 0;i < 26;++i) {
            if (pos[i] != -1 && x.pos[i] != -1) {
                d.push_back({ pos[i], x.pos[i],i });
            }
            else if (pos[i] != -1)res.pos[i] = pos[i];
            else if (x.pos[i] != -1)res.pos[i] = x.pos[i];
        }
        std::sort(d.begin(), d.end());
        int curr = -1;
        for (auto [l, r, c] : d) {
            if (l <= curr) {
                res.pos[c] = r;
            }
            else {
                rs.push_back({ l,r });
                curr = r;
            }
        }
        for (int i = 0;i < 26;++i)if (res.pos[i] != -1) {
            for (auto [l, r] : rs) {
                if (l <= i || i <= r) {
                    res.pos[i] = -1;
                    break;
                }
            }
        }
        return res;
    }
    i64 cal() {
        i64 res = 0;
        for (int i = 0;i < 26;++i)if (pos[i] != -1) {
            std::cout << pos[i] << " ";
            // res += b[pos[i]];
        }
        // std::cout << pos.size() << '\n';
        return res;
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
}
Info query(int ql, int qr, int l = 1, int r = n, int i = 1) {
    if (l > r)return Info();
    if (qr < l || r < ql)return Info();
    if (ql <= l && r <= qr)return tree[i];
    int mid = l + r >> 1;
    return query(ql, qr, l, mid, i << 1) + query(ql, qr, mid + 1, r, i << 1 | 1);
}

void solve() {
    // Info('a', 2);
    // Info('a', 1) + Info('b', 2);
    // std::cout << Info('a', 1).cal() << ' ';
    // std::cout << (Info('a', 1) + Info('b', 2)).cal();
    int n, q;std::cin >> n >> q;
    b.assign(n + 1, 0);
    std::cin >> s;s = "*" + s;
    for (int i = 1;i <= n;++i) {
        // Info(s[i], i);
        auto tmp = Info(s[i], i);
        update(i, tmp);
    }
    for (int i = 1;i <= n;++i)std::cin >> b[i];
    std::cout << q << '\n';
    while (q--) {
        int op, x, y;std::cin >> op >> x >> y;
        // if (op == 1) {
        //     // std::cout << x << ' ' << y << '\n';
        //     // b[x] = y;
        // }
        // else {
        //     if (x <= y) {
        //         // std::cout << query(x, y).cal();
        //     }
        //     else {
        //         // std::cout << (query(y, n) + query(1, x)).cal();
        //     }
        //     std::cout << '\n';
        // }
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t = 1;std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}