#include <bits/stdc++.h>
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
#define int long long
int nums[MAXN], n;
using pt = std::pair<int, int>;

using i128 = __int128;
// 重载输入运算符以支持__int128类型
std::istream& operator>>(std::istream& is, __int128& n) {
    std::string str;is >> str;
    n = 0;
    int st = (str[0] == '-');
    for (int i = st;i < str.size();i++) {
        n = n * 10 + str[i] - '0';
    }
    if (st == 1) n *= -1;
    return is;
}

//载输出运算符以支持__int128类型
std::ostream& operator<<(std::ostream& os, __int128 n) {
    std::string s;
    if (n == 0) s = "0";
    bool flag = false;
    if (n < 0) flag = true, n = -n;
    while (n) {
        s += '0' + n % 10;
        n /= 10;
    }
    if (flag) s += '-';
    std::reverse(s.begin(), s.end());
    return os << s;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n;
    std::map<int, int> mp;
    for (int i = 0;i < n;++i) {
        std::cin >> nums[i];
        mp[nums[i]]++;
    }
    std::sort(nums, nums + n, std::greater<int>());
    std::vector<int> ans;
    std::function<bool(int)> check = [&](int x) {
        if (x <= 0)return false;
        if (x % 2 == 0) {
            if (mp[x]) {
                mp[x]--;
                return true;
            }
            return false;
        }
        if (mp[x]) {
            mp[x]--;
            return true;
        }
        if (mp[(x + 1) / 2] && check(x / 2)) {
            mp[(x + 1) / 2]--;
            return true;
        }
        return false;
        };
    for (int i = 0;i < n;++i)if (mp[nums[i]]) {
        mp[nums[i]]--;
        if (nums[i] % 2) {
            if (check(nums[i] - 1))
                ans.push_back(nums[i] * 2 - 1);
            else ans.push_back(nums[i]);
            continue;
        }
        if (check(nums[i] + 1)) {
            ans.push_back(nums[i] * 2 + 1);
            continue;
        }
        if (check(nums[i] - 1)) {
            ans.push_back(nums[i] * 2 - 1);
            continue;
        }
        ans.push_back(nums[i]);
    }
    std::cout << ans.size() << '\n';
    for (int& x : ans)std::cout << x << ' ';
    return 0;
}