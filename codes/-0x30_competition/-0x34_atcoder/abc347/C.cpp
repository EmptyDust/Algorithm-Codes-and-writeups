#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10;
int nums[MAXN], n;
using pt = std::pair<int, int>;

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int a, b;
    std::cin >> n >> a >> b;
    int d = a + b;
    std::map<int, int> mp;
    for (int i = 0;i < n;++i) {
        std::cin >> nums[i];
        mp[nums[i] % d]++;
    }
    if ((*--mp.end()).first - (*mp.begin()).first < a) {
        std::cout << "Yes";
        return 0;
    }
    int pre = 0;
    for (auto [num, cnt] : mp) {
        if (num - pre > b) {
            std::cout << "Yes";
            return 0;
        }
        pre = num;
    }
    std::cout << "No";
    return 0;
}