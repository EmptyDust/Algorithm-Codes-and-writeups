#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;

struct dsu {
    std::vector<int> d;
    dsu(int n) { d.resize(n); iota(d.begin(), d.end(), 0); }
    int get_root(int x) { return d[x] = (x == d[x] ? x : get_root(d[x])); };
    bool merge(int u, int v) {
        if (get_root(u) != get_root(v)) {
            d[get_root(u)] = get_root(v);
            return true;
        }
        else return false;
    }
    i64 cal(bool f, std::vector<int>& nums) {
        int n = d.size();
        std::vector<int> cnt(n);
        for (int i = 0;i < n;++i)
            cnt[get_root(i)]++;
        i64 res = 0;
        for (int i = 0;i < n;++i)if (i == get_root(i)) {
            if (f && cnt[i] == 1 || nums[i] == 1) {
                res += n / 2 + 1 - std::abs(i - n / 2);
            }
            else res++;
        }
        return res;
    }
};

int p[MAXN];
void init() {
    for (int i = 2;i <= N;++i)if (!p[i]) {
        p[i] = i;
        for (i64 j = 1ll * i * i;j <= N;j += i) {
            p[j] = i;
        }
    }
}

int lst[MAXN];
void solve() {
    i64 n, k;
    std::cin >> n >> k;
    std::vector<int> nums(2 * n - 1);
    for (int i = n - 1;i < 2 * n - 1;++i)
        std::cin >> nums[i];
    for (int i = 0;i < n - 1;++i)
        nums[i] = nums[i + n];
    std::vector<int> nums_fb(nums);
    dsu d(2 * n - 1);
    std::vector<int> ini;
    for (int i = 0;i < 2 * n - 1;++i) {
        while (nums[i] >= 2) {
            int x = p[nums[i]];nums[i] /= x;
            ini.push_back(x);
            if (lst[x] != -1 && i - lst[x] <= k) d.merge(i, lst[x]);
            lst[x] = i;
        }
    }
    std::cout << d.cal(k == 1, nums_fb);
    for (int num : ini)
        lst[num] = -1;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    init();
    memset(lst, -1, sizeof lst);
    int t;std::cin >> t;
    while (t--) {
        solve();
        std::cout << '\n';
    }
    return 0;
}