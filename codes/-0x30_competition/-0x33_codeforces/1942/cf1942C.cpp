#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10;
using pt = std::pair<int, int>;

struct cmp {
    bool operator()(int a, int b)const {
        int x = a % 2, y = b % 2;
        if (x == y)return a < b;
        else return x;
    }
};

void solve() {
    int n, x, y;
    std::cin >> n >> x >> y;
    i64 ans = x - 2;
    std::map<int, int, cmp> mp;
    std::vector<int> nums(x);
    for (int i = 0;i < x;++i)std::cin >> nums[i];
    std::sort(nums.begin(), nums.end());
    int _dis = n - nums.back() + nums.front();
    if (_dis == 2)ans++;
    if (_dis > 2)mp[_dis - 1]++;
    for (int i = 1;i < x;++i) {
        int abs = nums[i] - nums[i - 1];
        if (abs == 2)ans++;
        if (abs > 2) {
            mp[abs - 1]++;
        }
    }
    for (auto [dis, cnt] : mp) {
        int nd = dis / 2;
        if (nd * cnt <= y) {
            y -= nd * cnt;
            ans += dis * cnt;
        }
        else {
            int can = y / nd;
            y -= can * nd;
            ans += dis * can;
            ans += y * 2;
            break;
        }
    }
    std::cout << ans;
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