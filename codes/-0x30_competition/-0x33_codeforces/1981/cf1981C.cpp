#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pt = std::pair<int, int>;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int& x : a)std::cin >> x;
    //1 2 4 8 16
    //1 3 7 15 31
    std::vector<int> ans(a);
    int fst = 0;
    while (fst < n && a[fst] == -1)fst++;
    if (fst == n) {
        for (int i = 0;i < n;++i) {
            if (i & 1)ans[i] = 1;
            else ans[i] = 2;
        }
        for (int x : ans)std::cout << x << ' ';
        return;
    }
    for (int i = 0;i < fst;++i) {
        if (i % 2 == fst % 2) ans[i] = a[fst];
        else
            ans[i] = a[fst] * 2;
    }
    int lst = n - 1;
    while (lst >= 0 && a[lst] == -1)lst--;
    for (int i = lst + 1;i < n;++i) {
        if (i % 2 == lst % 2)ans[i] = a[lst];
        else ans[i] = a[lst] * 2;
    }

    for (int l = fst, r = fst;r <= lst;++r) {
        if (a[r] == -1 || l == r)
            continue;
        if (l == r - 1) {
            l = r;
            continue;
        }
        int x = a[l], y = a[r];
        std::vector<int> nums1, nums2;
        while (x)nums1.push_back(x), x /= 2;
        while (y)nums2.push_back(y), y /= 2;
        int res = -inf, pos;
        for (int i = 0, j = 0;i < nums1.size() && j < nums2.size();) {
            if (nums1[i] > nums2[j])i++;
            else if (nums1[i] < nums2[j])j++;
            else {
                res = i + j;
                pos = nums1[i];
                break;
            }
        }
        res -= 2;
        if (res != -inf && res < r - l - 1 && (r - l - 1 - res) % 2 == 1) {
            int lb = l + 1, rb = r - 1;
            for (int cur = a[l] / 2;cur >= pos;cur /= 2, lb++) {
                ans[lb] = cur;
            }
            for (int cur = a[r] / 2;cur >= pos;cur /= 2, rb--) {
                ans[rb] = cur;
            }
            int num = ans[lb - 1];
            for (int x = lb;x <= rb;++x) {
                if ((x - lb) & 1)ans[x] = num;
                else ans[x] = num * 2;
            }
        }
        else {
            std::cout << -1;
            return;
        }
        l = r;
    }
    for (int i = 0;i < n;++i) {
        if (i)if (ans[i] != ans[i - 1] / 2 && ans[i] / 2 != ans[i - 1]) {
            std::cout << -1;
            return;
        }
        if (i != n - 1)if (ans[i] != ans[i + 1] / 2 && ans[i] / 2 != ans[i + 1]) {
            std::cout << -1;
            return;
        }
    }
    for (int x : ans)std::cout << x << ' ';
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