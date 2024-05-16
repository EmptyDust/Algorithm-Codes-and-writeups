#include <bits/stdc++.h>
using i64 = long long;
#define int long long
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pt = std::pair<int, int>;
int nums[MAXN], vis[MAXN], n;
i64 rk[MAXN];
i64 rd[MAXN];

std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n;
    for (int i = 0;i < n;++i)std::cin >> nums[i];
    for (int i = 1;i <= n;++i)rd[i] = rng();
    int cnt = 0;
    for (int i = 0;i < n;++i) {
        if (!vis[nums[i]]) {
            vis[nums[i]] = 1;
            rk[i] ^= rd[nums[i]];
            cnt++;
        }
    }
    for (int i = 1;i <= n;++i)vis[i] = 0;
    for (int i = n - 1;i >= 0;--i) {
        if (!vis[nums[i]]) {
            vis[nums[i]] = 1;
            rk[i] ^= rd[nums[i]];
        }
    }
    i64 cur = 0;
    for (int i = 0, pre = 0;i < n;++i) {
        cur ^= rk[i];
        if (cur == 0) {
            std::sort(nums + pre, nums + i + 1, std::greater<int>());
            pre = i + 1;
        }
    }
    //for (int x : vt)std::cout << x << ' ';
    std::vector<int> f(n);
    int len = 0;
    f[0] = 0;
    for (int i = 0;i < n;i++)
    {
        int l = 0, r = len, res = 0;
        while (l <= r)
        {
            int mid = l + r >> 1;
            if (f[mid] < nums[i]) {
                res = std::max(res, mid);
                l = mid + 1;
            }
            else r = mid - 1;
        }
        res++;
        len = std::max(len, res);
        f[res] = nums[i];
    }
    //std::cout << '\n';
    std::cout << cnt - len;
    return 0;
}