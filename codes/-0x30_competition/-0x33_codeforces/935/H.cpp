#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10;
using pt = std::pair<int, int>;

std::vector<int> a, b;

bool solve() {
    int n, x;std::cin >> n >> x;
    std::vector<int> nums(n), used(n, 0);
    for (auto& num : nums)std::cin >> num;
    int max = *std::max_element(nums.begin(), nums.end());
    int sx = std::__lg(max) + 1;
    std::vector<std::vector<int>> check(sx);
    std::vector<int> cnt(sx);
    for (auto& num : nums)for (int s = 0;s < sx;++s)
        cnt[s] += (num >> s & 1);
    int state = 0;
    for (int s = 0;s < sx;++s)if (cnt[s] == n - 1 || cnt[s] == n - 2)
        state |= 1 << s;
    std::vector<bool> mark(n);
    std::vector<int> v;
    for (int i = 0;i < n;++i) {
        bool ok = false;
        for (int s = 0;s < sx;++s) {
            if ((state >> s & 1) && !(nums[i] >> s & 1)) {
                ok = true;
                break;
            }
        }
        if (ok) {
            mark[i] = true;
            v.push_back(i);
        }
    }
    for (int pos : v) {
        for (int i = 0;i < n;++i) {
            if (pos == i)continue;
            int mask = 0;
            for (int s = 0;s < sx;++s) {
                int m = (nums[i] >> s & 1) + (nums[pos] >> s & 1);
                if (cnt[s] - m == n - 2)
                    mask |= 1 << s;
            }
            int gcd = std::__gcd(nums[i], nums[pos]);
            if (gcd > x + mask) {
                a.push_back(nums[i]);
                a.push_back(nums[pos]);
                for (int j = 0;j < n;++j)if (i != j && pos != j)
                    b.push_back(nums[j]);
                return true;
            }
        }
    }
    std::vector<int> f(max + 1);
    int res = (1 << sx) - 1;
    for (int i = 0;i < n;++i) {
        res &= nums[i];
        if (!mark[i])f[nums[i]]++;
    }
    for (int i = 1;i <= max;++i)
        for (int j = i * 2;j <= max;j += i)
            f[i] += f[j];
    int maxgcd = -1;
    for (int i = max;~i;--i)if (f[i] >= 2) {
        maxgcd = i;
        break;
    }
    if (maxgcd > res + x) {
        for (int i = 0;i < n;++i) {
            if (!mark[i] && nums[i] % maxgcd == 0 && a.size() < 2)
                a.push_back(nums[i]);
            else
                b.push_back(nums[i]);
        }
        return true;
    }
    return false;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t;std::cin >> t;
    while (t--) {
        if (solve()) {
            std::cout << "Yes" << '\n';
            std::cout << a.size() << ' ';
            for (int num : a)std::cout << num << ' ';
            std::cout << '\n';
            std::cout << b.size() << ' ';
            for (int num : b)std::cout << num << ' ';
            a.clear(), b.clear();
        }
        else std::cout << "No";
        std::cout << '\n';
    }
    return 0;
}