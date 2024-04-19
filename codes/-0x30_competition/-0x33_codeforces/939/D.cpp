#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10;
int nums[MAXN], n;
using pt = std::pair<int, int>;

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);

    std::cin >> n;
    for (int i = 1;i <= n;++i)std::cin >> nums[i];
    std::vector<i64> f(n + 1);
    std::vector<std::vector<pt>> ans(n + 1);
    for (int i = 1;i <= n;++i) {
        i64 res = -1, resi = -1;
        //从前面转移
        for (int j = 0;j < i;++j) {
            if (res < f[j] + (i - j) * (i - j)) {
                res = f[j] + (i - j) * (i - j);
                resi = j;
            }
        }
        if (res <= f[i - 1] + nums[i]) {
            resi = i - 1;
        }
        ans[i] = ans[resi];
        if (res <= f[i - 1] + nums[i])
            res = f[i - 1] + nums[i];
        else ans[i].push_back({ resi + 1,i });
        f[i] = res;
    }
    std::vector<pt> out;
    std::function<void(int, int, int)> dfs = [&](int x, int l, int r)->void {
        if (x == 1) {
            out.push_back({ l,l });
            return;
        }
        dfs(x - 1, l, r);
        out.push_back({ l,l + x - 1 });
        dfs(x - 1, l, r);
        };
    for (auto& [l, r] : ans[n]) {
        int len = r - l + 1;
        for (int i = l + 1;i <= r;++i)if (nums[i])out.push_back({ i,i });
        if (!nums[l])out.push_back({ l,l });
        dfs(len, l, r);
        out.push_back({ l,r });
    }
    std::cout << f[n] << ' ' << out.size() << '\n';
    for (auto& [l, r] : out) {
        std::cout << l << ' ' << r << '\n';
    }
    return 0;
}