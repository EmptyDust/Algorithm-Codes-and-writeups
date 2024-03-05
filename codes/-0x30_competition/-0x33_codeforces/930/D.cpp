#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10;
int n;

using pt = std::pair<int, int>;

void solve() {
    std::cin >> n;
    std::vector<bool> nums(n);
    std::string s;std::cin >> s;
    for (int i = 0;i < n;++i)nums[i] = s[i] == '>';
    auto dp = [&]()->auto {
        std::vector<i64> ans;
        i64 cnt = 0, h = 0, lx = 0, rx = 0;
        for (int l = 0, r = 0;r < n && l < n;++l) {
            lx += cnt;
            rx -= cnt;
            if (nums[l]) cnt++;
            else h--;
            while (h < cnt) {
                while (r < n && nums[r])r++;
                if (r == n)return ans;
                rx += r - l;
                h++;
                r++;
            }
            i64 res = l + 1 + (lx + rx) * 2;
            ans.push_back(res);
        }
        return ans;
        };
    auto ans1 = dp();
    std::reverse(nums.begin(), nums.end());
    for (int i = 0;i < n;++i)nums[i] = !nums[i];
    auto ans2 = dp();
    std::reverse(ans2.begin(), ans2.end());
    for (auto num : ans1)std::cout << num << ' ';
    for (auto num : ans2)std::cout << num << ' ';
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t;std::cin >> t;
    while (t--) {
        solve();
        std::cout << '\n';
    }
    return 0;
}