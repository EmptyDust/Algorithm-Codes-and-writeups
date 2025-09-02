#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using u128 = unsigned __int128;

using a2 = std::array<int, 2>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
// const int mod = 1e9 + 7;
const int mod = 998244353;

a3 cal_max(std::vector<int>& a, int n, int k) {
    auto l = 1, r = n + 1;
    auto check = [&](auto x)->bool {
        // std::cout << x << ' ';
        auto b(a);
        for (int i = 1;i <= n;++i) {
            b[i] = (b[i] >= x ? 1 : -1);
            b[i] += b[i - 1];
        }
        int min = 0, minp = 0;
        for (int i = k;i <= n;++i) {
            if (min > b[i - k]) {
                min = b[i - k];
                minp = i - k;
            }
            if (b[i] >= min) return 0;
        }
        // std::cout << "no";
        return 1;
        };
    while (l < r) {
        auto mid = l + r >> 1;
        if (check(mid))r = mid;
        else l = mid + 1;
    }
    int ans = l - 1;

    auto b(a);
    for (int i = 1;i <= n;++i) {
        b[i] = (b[i] >= ans ? 1 : -1);
        b[i] += b[i - 1];
    }
    int min = 0, minp = 0;
    for (int i = k;i <= n;++i) {
        if (min > b[i - k]) {
            min = b[i - k];
            minp = i - k;
        }
        if (b[i] >= min) {
            return { ans, minp + 1, i };
        }
    }
    assert(0);
    return { -1, -1, -1 };
}

a3 cal_min(std::vector<int>& a, int n, int k) {
    auto l = 1, r = n + 1;
    auto check = [&](auto x)->bool {
        // std::cout << x << ' ';
        auto b(a);
        for (int i = 1;i <= n;++i) {
            b[i] = (b[i] <= x ? 1 : -1);
            b[i] += b[i - 1];
        }
        int min = 0, minp = 0;
        for (int i = k;i <= n;++i) {
            if (min > b[i - k]) {
                min = b[i - k];
                minp = i - k;
            }
            if (b[i] >= min) return 1;
        }
        // std::cout << "no";
        return 0;
        };
    while (l < r) {
        auto mid = l + r >> 1;
        if (check(mid))r = mid;
        else l = mid + 1;
    }
    // std::cout << l << ' ';
    int ans = l;
    // std::cout << check(1) << ' ';
    // std::cout << check(2) << ' ';

    auto b(a);
    for (int i = 1;i <= n;++i) {
        b[i] = (b[i] <= ans ? 1 : -1);
        b[i] += b[i - 1];
    }
    int min = 0, minp = 0;
    for (int i = k;i <= n;++i) {
        if (min > b[i - k]) {
            min = b[i - k];
            minp = i - k;
        }
        if (b[i] >= min) {
            return { ans, minp + 1, i };
        }
    }
    assert(0);
    return { -1, -1, -1 };
}

namespace Set {
    const int kInf = 1e9 + 1919810;
    std::multiset<int> less, greater;
    void init() {
        less.clear(), greater.clear();
        less.insert(-kInf), greater.insert(kInf);
    }
    void adjust() {
        while (less.size() > greater.size() + 1) {
            std::multiset<int>::iterator it = (--less.end());
            greater.insert(*it);
            less.erase(it);
        }
        while (greater.size() > less.size()) {
            std::multiset<int>::iterator it = greater.begin();
            less.insert(*it);
            greater.erase(it);
        }
    }
    void add(int val_) {
        if (val_ <= *greater.begin()) less.insert(val_);
        else greater.insert(val_);
        adjust();
    }
    void del(int val_) {
        std::multiset<int>::iterator it = less.lower_bound(val_);
        if (it != less.end()) {
            less.erase(it);
        }
        else {
            it = greater.lower_bound(val_);
            greater.erase(it);
        }
        adjust();
    }
    int get_middle() {
        // if (*less.rbegin() == 1) {
        //     for (auto x : less)std::cout << x << ' ';std::cout << '\n';
        //     for (auto x : greater)std::cout << x << ' ';std::cout << '\n';
        // }
        return *less.rbegin();
    }
    int get_middle2() {
        return *greater.begin();
    }
}

void solve() {
    Set::init();
    int n, k;std::cin >> n >> k;
    std::vector<int> a(n + 1);
    for (int i = 1;i <= n;++i)
        std::cin >> a[i];
    auto [max, maxl, maxr] = cal_max(a, n, k);
    // std::cout << max << ' ' << maxl << ' ' << maxr << '\n';
    auto [min, minl, minr] = cal_min(a, n, k);
    // std::cout << min << ' ' << minl << ' ' << minr << '\n';
    std::vector<a2> now = { {maxl,maxr},{minl,minr} };
    ranges::sort(now);

    std::vector<a4> res;
    auto add = [&](int l, int r) {
        int len = r - l + 1;
        if (len % 2) res.push_back({ Set::get_middle(), Set::get_middle(), l, r });
        else res.push_back({ Set::get_middle(), Set::get_middle2(),  l, r });
        };

    auto [l1, r1] = now[0];
    auto [l2, r2] = now[1];
    for (int i = l1;i <= r1;++i) Set::add(a[i]);
    Set::adjust();
    add(l1, r1);
    while (r1 < r2) {
        r1++;
        Set::add(a[r1]);
        Set::adjust();
        add(l1, r1);
    }
    while (r1 > r2) {
        Set::del(a[r1]);
        r1--;
        Set::adjust();
        add(l1, r1);
    }
    while (l1 < l2) {
        Set::del(a[l1]);
        l1++;
        Set::adjust();
        add(l1, r1);
    }
    ranges::sort(res);
    std::vector<a3> ans;
    int cur = 1;
    for (auto [x, y, l, r] : res) {
        cur = std::max(cur, x);
        while (cur <= y) {
            ans.push_back({ cur, l, r });
            cur++;
        }
    }
    std::cout << ans.size() << '\n';
    for (auto [p, l, r] : ans)
        std::cout << p << ' ' << l << ' ' << r << '\n';
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t;std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}