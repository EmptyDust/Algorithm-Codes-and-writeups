#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 30, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
i64 nums[MAXN];
int n;
using pt = std::pair<int, int>;

#define ln(x) x*2
#define rn(x) x*2+1
i64 segment_tree[MAXN], lazy_tag[MAXN];
void push_up(int x) {
    segment_tree[x] = segment_tree[ln(x)] + segment_tree[rn(x)];
}

void setup(int l = 1, int r = n, int i = 1) {
    if (r < l)return;
    if (l == r) {
        segment_tree[i] = nums[l];
        return;
    }
    auto mid = l + r >> 1;
    setup(l, mid, ln(i));
    setup(mid + 1, r, rn(i));
    push_up(i);
}

void push_down(int x, int l, int r) {
    lazy_tag[ln(x)] += lazy_tag[x];
    lazy_tag[rn(x)] += lazy_tag[x];
    int mid = l + r >> 1;
    segment_tree[ln(x)] += (mid - l + 1) * lazy_tag[x];
    segment_tree[rn(x)] += (r - mid) * lazy_tag[x];
    lazy_tag[x] = 0;
}

void update(int ul, int ur, int x, int l = 1, int r = n, int i = 1) {
    if (r < l)return;
    if (ul > r || ur < l)return;
    if (ul <= l && r <= ur) {
        lazy_tag[i] += x;
        segment_tree[i] += (r - l + 1) * x;
        return;
    }
    auto mid = l + r >> 1;
    push_down(i, l, r);
    update(ul, ur, x, l, mid, ln(i));
    update(ul, ur, x, mid + 1, r, rn(i));
    push_up(i);
}

i64 query(int pos, int l = 1, int r = n, int i = 1) {
    if (r < l)return 0;
    if (pos > r || pos < l)return 0;
    if (l == pos && pos == r)
        return segment_tree[i];
    auto mid = l + r >> 1;
    push_down(i, l, r);
    return query(pos, l, mid, ln(i)) + query(pos, mid + 1, r, rn(i));
}

int p[N + 1];
bool add_basis(i64 x) {
    for (int s = N;s >= 0;--s)if (x >> s & 1) {
        if (!p[s]) {
            p[s] = x;
            break;
        }
        x ^= p[s];
        if (x == 0)return true;
    }
    return false;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int m;std::cin >> n >> m;
    for (int i = 1;i <= n;++i)std::cin >> nums[i];
    setup();
    int op, l, r, x;
    while (m--) {
        std::cin >> op >> l >> r;
        if (op == 1) {
            std::cin >> x;
            update(l, r, x);
        }
        else {
            memset(p, 0, sizeof p);
            bool f = false;
            for (int q = l;q <= r;++q) {
                int num = query(q);
                //std::cout << num << ' ';
                if (add_basis(num)) {
                    f = true;
                    break;
                }
            }
            if (f)std::cout << "Yes\n";
            else std::cout << "No\n";
        }
    }
    return 0;
}