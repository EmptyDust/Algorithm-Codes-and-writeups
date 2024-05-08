#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
int nums[MAXN], n, q;
bool rev[20], swap[20];
using pt = std::pair<int, int>;

struct segment_node
{
    int l, r;
    segment_node* left = nullptr, * right = nullptr;
    int len;
    i64 sum = 0;
};

void setup(int l, int r, int len = n, segment_node* node) {
    node->l = l;
    node->r = r;
    if (l == r) {
        node->sum = nums[l];
        return;
    }
    node->left = new segment_node();
    node->right = new segment_node();
    int mid = l + r >> 1;
    setup(l, mid, len - 1, node->left);
    setup(mid + 1, r, len - 1, node->right);
    node->sum = node->left->sum + node->right->sum;
}

void replace(int x, int k, segment_node* node) {
    if (node->l > x || node->r < x)return;
    if (node->l == x && node->r == x) {
        node->sum = k;
        return;
    }
    if (rev[node->len])
        x = node->l + (node->r - (x - node->l));
    if (swap[node->len - 1]) {
        int mid = node->l + node->r >> 1;
        int len = node->r - mid;
        if (x > mid)x -= len;
        else x += len;
    }
    replace(x, k, node->left);
    replace(x, k, node->right);
    node->sum = node->left->sum + node->right->sum;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n >> q;
    for (int i = 1;i <= n;++i)std::cin >> nums[i];

    return 0;
}