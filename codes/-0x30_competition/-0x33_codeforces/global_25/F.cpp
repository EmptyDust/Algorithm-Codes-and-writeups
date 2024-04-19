#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10;
int nums[MAXN], n;
using pt = std::pair<int, int>;

struct indexed_tree {
#define lowbit(x) x&-x
    std::vector<i64> i_tree;
    i64 n;
    indexed_tree(int x) {
        i_tree.assign(x + 1, 0);
        n = x;
    }
    void update(int pos, i64 x) {
        for (int i = pos;i <= n;i += lowbit(i)) {
            i_tree[i] += x;
        }
    }
    i64 query(int pos) {
        i64 res = 0;
        for (int i = pos;i;i -= lowbit(i)) {
            res += i_tree[i];
        }
        return res;
    }
#undef lowbit(x)
};

i64 count_inversion(std::vector<int> nums) {
    int n = nums.size();
    /*
    std::vector<int> f(n), zbs(n);
    std::iota(zbs.begin(), zbs.end(), 0);
    std::sort(zbs.begin(), zbs.end(), [&](int a, int b) {return nums[a] < nums[b];});
    for (int i = 0;i < n;++i) {
        if (i && nums[zbs[i]] == nums[zbs[i - 1]])f[zbs[i]] = f[zbs[i - 1]];
        else f[zbs[i]] = i + 1;
    }
    */
    indexed_tree* t = new indexed_tree(n);
    i64 res = 0;
    for (int i = 0;i < n;++i) {
        res += i;
        res -= t->query(nums[i]);
        t->update(nums[i], 1);
    }
    return res;
}

void solve() {
    int n, k;std::cin >> n >> k;
    std::vector<int>nums(n);
    for (int& num : nums)std::cin >> num;
    int cnt = count_inversion(nums);
    if (cnt > k || (k - cnt) % 2) {
        std::cout << "No";
        return;
    }
    if (cnt == k) {
        std::cout << "Yes";
        for (int i = 1;i <= n;++i)std::cout << i << ' ';
        return;
    }
    std::vector<int> zbs(n), ans;
    std::iota(zbs.begin(), zbs.end(), 0);
    std::iota(ans.begin(), ans.end(), 1);
    std::sort(zbs.begin(), zbs.end(), [&](int a, int b) {return nums[a] < nums[b];});
    int pre = 0;
    for (int i = n - 1;i >= 0;--i) {
        int m = zbs[i] * 2;
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t;std::cin >> t;
    while (t--) {
        solve();
        std::cout << '\n';
    }
    return 0;
}