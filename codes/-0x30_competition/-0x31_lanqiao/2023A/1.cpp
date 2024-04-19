#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10;
int nums[MAXN], n;
using pt = std::pair<int, int>;

bool check(int x) {
    int len = 0;
    int tmp = x;
    while (tmp)tmp /= 10, len++;
    if (len % 2)return false;
    int a = 0, b = 0;
    for (int i = 0;i < len / 2;++i) { a += x % 10;x /= 10; }
    for (int i = 0;i < len / 2;++i) { b += x % 10;x /= 10; }
    return a == b;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int res = 0;
    for (int i = 1;i <= 1e8;++i) {
        if (check(i))res++;
    }
    std::cout << res;
    return 0;
}