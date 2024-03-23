#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10;
int nums[MAXN], n;
using pt = std::pair<int, int>;

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int n, q;std::cin >> n >> q;
    std::vector<i64> nums(n), time(n, 0);
    for (int i = 0;i < n;++i)std::cin >> nums[i];
    i64 sum = std::accumulate(nums.begin(), nums.end(), (i64)0);
    i64 t = -1, de = -1;
    for (int i = 1;i <= q;++i) {
        int op;std::cin >> op;
        if (op == 1) {
            i64 pos, x;
            std::cin >> pos >> x;
            pos--;
            if (time[pos] > t)
                sum += x - nums[pos];
            else
                sum += x - de;
            nums[pos] = x;
            time[pos] = i;
        }
        if (op == 2) {
            i64 x;std::cin >> x;
            t = i;
            de = x;
            sum = x * n;
        }
        std::cout << sum << std::endl;
    }
    return 0;
}