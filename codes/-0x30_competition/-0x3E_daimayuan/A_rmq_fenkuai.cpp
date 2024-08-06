#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;

namespace block {
    struct block
    {
        std::vector<int> nums;
        std::vector<int> pre, suf;
        int min = inf;
        block(int sz) {
            nums.assign(sz, inf);
            pre.assign(sz, 0);
            suf.assign(sz, 0);
        }
        void init() {
            for (int i = 0;i < nums.size();++i)
                min = std::min(min, nums[i]);
            for (int i = 0;i < nums.size();++i) {
                if (i)pre[i] = std::min(pre[i - 1], nums[i]);
                else pre[i] = nums[i];
            }
            for (int i = nums.size() - 1;i >= 0;--i) {
                if (i != nums.size() - 1)suf[i] = std::min(suf[i + 1], nums[i]);
                else suf[i] = nums[i];
            }
        }
    };
    std::vector<int> origin;
    int m;
    std::vector<block> blocks;
    std::vector<std::vector<int>> result;

    void init(std::vector<int>& a) {
        origin = a;
        int sz = a.size();
        m = std::sqrt(sz);
        blocks.assign(m + 1, block(m));
        result.assign(m + 1, std::vector<int>(m + 1, inf));
        for (int i = 0;i < sz;++i) {
            blocks[i / m].nums[i % m] = a[i];
        }
        for (auto& b : blocks) {
            b.init();
        }
        for (int i = 0;i <= m;++i) {
            int min = inf;
            for (int j = i;j <= m;++j) {
                min = std::min(min, blocks[j].min);
                result[i][j] = min;
            }
        }
    }

    int query(int l, int r) {//[l,r)
        int len = r - l;
        r--;
        int a = l / m;
        int b = r / m;
        if (a == b) {
            int min = inf;
            for (int i = l;i <= r;++i) {
                min = std::min(min, origin[i]);
            }
            return min;
        }
        return std::min({ result[a + 1][b - 1],blocks[a].suf[l % m],blocks[b].pre[r % m] });
    }
}


signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int n, q;std::cin >> n >> q;
    std::vector<int> a(n);
    for (int& x : a)std::cin >> x;
    block::init(a);
    while (q--) {
        int l, r;std::cin >> l >> r;
        std::cout << block::query(l, r) << '\n';
    }
    return 0;
}