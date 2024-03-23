#include<bits/stdc++.h>
constexpr int MAXN = 3e5 + 10;
int a[MAXN], b[MAXN], c[MAXN];
using i64 = long long;

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int n;std::cin >> n;
    int lg = std::__lg(n);
    std::vector<int> nums(n + 1, 0);
    std::cout << '*';
    for (int i = 0;i < n;++i)std::cout << "****";
    std::cout << "**" << '\n';
    for (int s = lg;s;--s) {
        std::vector<int> nnums(nums);
        int f = -1;
        for (int i = 1;i <= n;++i) {
            nnums[i] = (i & 1 << s);
            f = i;
        }
        std::cout << '*' << '+';
        int i = 1;
        for (;i < n;++i) {
            if (nnums[i] || nnums[i - 1] || nums[i] || nums[i - 1]) {
                std::cout << '+';
            }
            else std::cout << '-';
            if (f == i)break;
            std::cout << "---";
        }
        nums = nnums;
        std::cout << '\n';
    }
    std::cout << '*';
    for (int i = 0;i < n;++i)std::cout << "****";
    std::cout << "**" << '\n';
    return 0;
}

/*
*******************************
*+------------+---+---+---
*+----+---+---+---+---+---
*******************************

*******************************
*+-----------+---+            *
*|           |4  |            *
*+---+---+---+---+---+---+    *
*|   |2  |       |   |6  |    *
*+---+---+---+   +---+---+---+*
*|1  |   |3  |   |5  |   |7  |*
*+---+---+---+---+---+---+---+*
*|1  |2  |3  |4  |5  |6  |7  |*
*+---+---+---+---+---+---+---+*
*******************************
*/