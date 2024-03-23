#include<bits/stdc++.h>
constexpr int MAXN = 1e6 + 10;
int nums[MAXN];
using i64 = long long;

signed main() {
    int n;std::cin >> n;
    int num;
    i64 res = 0;
    for (int i = 0;i < n;++i) {
        std::cin >> num;
        if (num != 1)
            res += num;
    }
    std::cout << res;
    return 0;
}