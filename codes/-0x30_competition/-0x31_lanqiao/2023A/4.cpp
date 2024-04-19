#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10;
using pt = std::pair<int, int>;

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    std::string s;std::cin >> s;
    int n = s.length();
    std::vector<int> nums(n);
    for (int i = 0;i < n;++i)nums[i] = (s[i] - '0');
    int cnt = 0;
    for (int i = 0;i < n;++i) {
        int l = i, r = i;
        while (0 <= l && r < n && nums[l] == nums[r])l--, r++;
        bool f = true;
        while (0 <= l && r < n) {
            if (nums[r] != nums[l])
                f = (nums[r] < nums[l]);
            cnt += f;
            l--, r++;
        }
    }
    for (int i = 1;i < n;++i) {
        int l = i - 1, r = i;
        while (0 <= l && r < n && nums[l] == nums[r])l--, r++;
        bool f = true;
        while (0 <= l && r < n) {
            if (nums[r] != nums[l])
                f = (nums[r] < nums[l]);
            cnt += f;
            l--, r++;
        }
    }
    std::cout << cnt;
    return 0;
}