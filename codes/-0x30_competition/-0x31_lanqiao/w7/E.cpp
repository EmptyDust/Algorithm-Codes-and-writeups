#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10;
int n;
using pt = std::pair<int, int>;
std::vector<i64> nums, pts;

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int k, n;std::cin >> k >> n;
    i64 minb = 1e9, suma = 0, bossb;
    i64 a, b;
    for (int i = 0;i < k;++i) {
        std::cin >> a >> b;
        suma += a;
        if (i != k - 1) {
            pts.push_back(b);
            nums.push_back(a);
            minb = std::min(minb, b);
        }
        else
            bossb = b;
    }
    sort(nums.begin(), nums.end());
    i64 ans = n >= k ? suma + (n - k) * bossb : std::accumulate(nums.begin(), nums.begin() + n, (i64)0);
    suma = 0;
    int j = 0;
    while (j < k - 1 && nums[j] <= minb) {
        suma += nums[j];
        j++;
    }
    i64 tmp = (n - j >= 0) ? suma + (n - j) * minb : 1e18;
    ans = std::min(ans, tmp);
    std::cout << ans;
    return 0;
}