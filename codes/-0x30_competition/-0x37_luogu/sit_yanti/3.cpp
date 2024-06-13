#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pt = std::pair<int, int>;

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int n, m;std::cin >> m >> n;
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0;i < n;++i) {
        int num;
        std::cin >> num;
        if (num == 1)cnt1++;
        else cnt2++;
    }
    bool res;
    if (cnt1 + cnt2 * 2 <= 4) {
        res = (cnt1 + cnt2) % 2;
    }
    else if (cnt1 >= 2 && cnt2 >= 1) {
        res = 1;
    }
    else {
        res = 0;
    }

    std::cout << (res ? "Yes" : "No");
    return 0;
}