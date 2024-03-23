#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10;
int nums[MAXN], n;
using pt = std::pair<int, int>;

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    std::unordered_map<int, int> pre, suf;
    int n;std::cin >> n;
    for (int i = 0;i < n;++i) {
        std::cin >> nums[i];
        if (i)pre[nums[i]] = nums[i - 1];
    }
    for (int i = 0;i < n - 1;++i)
        suf[nums[i]] = nums[i + 1];
    suf[0] = nums[0];
    pre[0] = nums[n - 1];
    pre[nums[0]] = 0;
    suf[nums[n - 1]] = 0;
    int q;std::cin >> q;
    while (q--) {
        int op, x;std::cin >> op >> x;
        if (op == 1) {
            int y;std::cin >> y;
            suf[y] = suf[x];
            pre[suf[x]] = y;
            pre[y] = x;
            suf[x] = y;
        }
        else {
            suf[pre[x]] = suf[x];
            pre[suf[x]] = pre[x];
        }
    }
    int a = 0;
    while (1) {
        a = suf[a];
        if (!a)break;
        std::cout << a << ' ';
    }
    return 0;
}