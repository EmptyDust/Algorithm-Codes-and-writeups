#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
int nums[MAXN], n;
using pt = std::pair<int, int>;
using a4 = std::array<int, 4>;

int D[MAXN], X[MAXN];

#define ln(x) (x*2)
#define rn(x) (x*2+1)
i64 segment_tree[MAXN << 2], covered[MAXN << 2];
void push_up(int x, int l, int r) {
    if (segment_tree[x])covered[x] = r - l + 1;
    else covered[x] = covered[ln(x)] + covered[rn(x)];
}

void update(int ul, int ur, int x, int l = 1, int r = n, int i = 1) {
    if (r < l)return;
    if (ul > r || ur < l)return;
    if (ul <= l && r <= ur) {
        segment_tree[i] += (r - l + 1) * x;
        covered[i] = r - l + 1;
        return;
    }
    auto mid = l + r >> 1;
    update(ul, ur, x, l, mid, ln(i));
    update(ul, ur, x, mid + 1, r, rn(i));
    push_up(i, l, r);
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int n;
    std::vector<a4> edges(n);
    int x1, y1, x2, y2;
    for (int i = 0;i < n;++i) {
        std::cin >> x1 >> y1 >> x2 >> y2;
        X[ln(i)] = x1;
        X[rn(i)] = x2;
        edges[i] = { y1,x1,x2,1 };
        edges[i] = { y2,x1,x2,-1 };
    }
    std::sort(edges.begin(), edges.end());
    std::iota(D, D + n, 0);
    return 0;
}