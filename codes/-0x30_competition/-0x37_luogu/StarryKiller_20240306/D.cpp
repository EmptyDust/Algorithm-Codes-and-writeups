#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 350;
int nums[MAXN], n, cnt[5], f[5][40][40][40][40];
using pt = std::pair<int, int>;

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    memset(f, -1, sizeof f);
    int n, m;std::cin >> n >> m;
    for (int i = 0;i < n;++i)std::cin >> nums[i];
    for (int i = 0;i < m;++i) {
        int x;std::cin >> x;
        cnt[x]++;
    }
    f[0][cnt[1]][cnt[2]][cnt[3]][cnt[4]] = nums[0];
    for (int i = 0;i < n;++i) {
        for (int a4 = std::min(cnt[4], (n - i) / 4);a4 >= std::max(0, cnt[4] - i);--a4) {
            for (int a3 = std::min(cnt[3], (n - i) / 3);a3 >= std::max(0, cnt[3] - i);--a3) {
                for (int a2 = std::min(cnt[2], (n - i) / 2);a2 >= std::max(0, cnt[2] - i);--a2) {
                    for (int a1 = std::min(cnt[1], n - i);a1 >= std::max(0, cnt[1] - i);--a1) {
                        if (f[i % 5][a1][a2][a3][a4] == -1)continue;
                        if (a1)
                            f[(i + 1) % 5][a1 - 1][a2][a3][a4] = std::max(f[(i + 1) % 5][a1 - 1][a2][a3][a4], f[i % 5][a1][a2][a3][a4] + nums[i + 1]);
                        if (a2)
                            f[(i + 2) % 5][a1][a2 - 1][a3][a4] = std::max(f[(i + 2) % 5][a1][a2 - 1][a3][a4], f[i % 5][a1][a2][a3][a4] + nums[i + 2]);
                        if (a3)
                            f[(i + 3) % 5][a1][a2][a3 - 1][a4] = std::max(f[(i + 3) % 5][a1][a2][a3 - 1][a4], f[i % 5][a1][a2][a3][a4] + nums[i + 3]);
                        if (a4)
                            f[(i + 4) % 5][a1][a2][a3][a4 - 1] = std::max(f[(i + 4) % 5][a1][a2][a3][a4 - 1], f[i % 5][a1][a2][a3][a4] + nums[i + 4]);
                    }
                }
            }
        }
    }
    int res = f[(n - 1) % 5][0][0][0][0];
    std::cout << res;
    return 0;
}