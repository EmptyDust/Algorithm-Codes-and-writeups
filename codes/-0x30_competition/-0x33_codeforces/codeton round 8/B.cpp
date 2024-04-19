#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10;
int nums[MAXN], n;
using pt = std::pair<int, int>;

void solve() {
    int mex = 0, mmex = 0;
    std::cin >> n;
    for (int i = 0;i < n;++i)std::cin >> nums[i];
    std::vector<int> f(n, 0), f2(n, 0), ans;
    for (int i = 0;i < n;++i) {
        f2[mex] = 1;
        while (mmex < n && (f[mmex] || f2[mmex]))mmex++;
        if (mmex - nums[i] == mex) {
            ans.push_back(mex);
            mex = mmex;
        }
        else {
            ans.push_back(mex - nums[i]);
            f[mex - nums[i]] = 1;
        }
        while (mex < n && f[mex])mex++;
    }
    for (int num : ans)std::cout << num << ' ';
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