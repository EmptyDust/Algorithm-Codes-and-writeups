#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
int nums[MAXN], n;
using pt = std::pair<int, int>;

i64 BSGS(i64 a, i64 b, i64 m, i64 k = 1) {
    static std::unordered_map<i64, i64> hs;
    hs.clear();
    i64 cur = 1, t = sqrt(m) + 1;
    for (int B = 1; B <= t; ++B) {
        (cur *= a) %= m;
        hs[b * cur % m] = B; // 哈希表中存B的值
    }
    i64 now = cur * k % m;
    for (int A = 1; A <= t; ++A) {
        auto it = hs.find(now);
        if (it != hs.end()) return A * t - it->second;
        (now *= cur) %= m;
    }
    return -inf; // 这里因为要多次加1，要返回更小的负数
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);

    return 0;
}