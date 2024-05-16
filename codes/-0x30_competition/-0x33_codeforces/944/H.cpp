#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pt = std::pair<int, int>;

void solve() {
    int n;std::cin >> n;
    std::vector<std::vector<int>> nums(n, std::vector<int>(3));
    std::map<pt, std::vector<int>> mp;
    std::vector<int> ans(n + 1, 0);
    for (int i = 0;i < 3;++i)
        for (int j = 0;j < n;++j)
            std::cin >> nums[j][i];

    for (int i = 0;i < n;++i) {
        for (int j = 0;j < 3;++j)for (int k = j + 1;k < 3;++k) {
            int x = nums[i][j], y = nums[i][k], z;
            for (int t = 0;t < 3;++t)if (t != k && t != j)z = nums[i][t];
            if (x > y)std::swap(x, y);
            if (x == y) {
                ans[std::abs(x)] = (x > 0 ? 1 : -1);
                continue;
            }
            if (x == -y) {
                ans[std::abs(z)] = (z > 0 ? 1 : -1);
                continue;
            }
            mp[{x, y}].push_back(z);
        }
    }
    for (int i = 1;i <= n;++i)std::cout << ans[i] << ' ';

    for (int t = 0;t < 4;++t) {
        for (auto& [pt, vt] : mp) {
            auto& [x, y] = pt;
            if (ans[std::abs(x)] && ans[std::abs(y)] && ans[std::abs(x)] != ans[std::abs(y)]) {
                for (int& z : vt) {
                    int res = (z > 0 ? 1 : -1);
                    if (ans[std::abs(z)] != res) {
                        std::cout << "No";
                        return;
                    }
                    ans[z] = res;
                }
            }
        }
    }
    std::cout << "Yes";
    /*
    for (int i = 0;i < n;++i) {
        std::map<int, int> mp;
        int cnt0 = 0, cnt1 = 0;
        for (int j = 0;j < 3;++j) {
            mp[nums[i][j]]++;
            if (ans[nums[i][j]] == 1)cnt1++;
            if (ans[nums[i][j]] == -1)cnt0++;
        }
        if (cnt0 >= 2) {
            std::cout << "NO";
            return;
        }
        if (cnt1 >= 2) {
            continue;
        }
        if (cnt0 == 1) {
            for (int j = 0;j < 3;++j)if (!ans[nums[i][j]]) {
                ans[nums[i][j]] = (nums[i][j] > 0 ? 1 : -1);
            }
            continue;
        }
        if (cnt1 == 1) {

        }
        if (!cnt0 && !cnt1) {
            for (auto& [num, cnt] : mp) if (!ans[num]) {
                if (cnt >= 2) {
                    ans[i] = (num > 0 ? 1 : -1);
                    break;
                }
                else if (mp[-num] >= 2) {
                    ans[i] = (num > 0 ? -1 : 1);
                    break;
                }
                else if (cnt + mp[-num] >= 2) {
                    for (auto& [x, cnt] : mp)if (x != num && x != -num) {
                        ans[x] = 1;
                        break;
                    }
                    break;
                }
            }
            continue;
        }
    }
    */
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