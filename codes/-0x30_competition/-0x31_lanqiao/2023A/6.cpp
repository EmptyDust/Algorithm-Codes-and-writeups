#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 100;
i64 nums[MAXN], suf[MAXN], n, m;
using pt = std::pair<i64, i64>;

i64 ans = 1e9;
bool check(int x, i64 cur, int p) {
    if (p >= ans)return false;
    if (cur + suf[x] < m)return false;
    if (cur > m)return false;
    return true;
}
void dfs(int x, i64 cur, int p) {
    if (!check(x, cur, p))return;
    if (cur == m) {
        ans = p;
        return;
    }
    dfs(x + 1, cur + nums[x] * 2, p);
    dfs(x + 1, cur + nums[x], p + 1);
    dfs(x + 1, cur, p);
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n >> m;m *= 2;
    for (int i = 0;i < n;++i)std::cin >> nums[i];
    std::sort(nums, nums + n, std::greater<i64>());
    for (int i = n - 1;i >= 0;--i)
        suf[i] = suf[i + 1] + nums[i] * 2;
    dfs(0, 0, 0);
    std::cout << (ans == 1e9 ? -1 : ans);
    return 0;
}