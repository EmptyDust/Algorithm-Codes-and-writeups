#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
int nums[MAXN], n;
using pt = std::pair<int, int>;

void solve() {
    std::cin >> n;
    for (int i = 0;i < n;++i)std::cin >> nums[i];
    int pos = std::max_element(nums, nums + n) - nums;
    int p = pos & 1;
    std::vector<int> poss, poss2;
    for (int i = 0;i < n;++i) {
        if (i == pos)continue;
        if (i % 2 == p && i != pos)
            poss.push_back(i);
        else poss2.push_back(i);
    }
    std::sort(poss.begin(), poss.end(), [&](int a, int b) {return nums[a] < nums[b];});
    std::sort(poss2.begin(), poss2.end(), [&](int a, int b) {return nums[a] > nums[b];});
    std::vector<int> ans(n);
    for (int i = n, j = 0;i > n / 2 + 1;--i, ++j)
        ans[poss[j]] = i;
    ans[pos] = n / 2 + 1;
    for (int i = 0;i < n / 2;++i)
        ans[poss2[i]] = i + 1;
    for (int x : ans)std::cout << x << ' ';
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