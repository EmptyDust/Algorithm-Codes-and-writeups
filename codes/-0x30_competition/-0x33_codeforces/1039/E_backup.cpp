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

namespace Set {
    const int kInf = 1e9 + 2077;
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
    std::vector<int> a(n);
    for (auto& x : a)std::cin >> x;
    for (int i = 0;i < k;++i) Set::add(a[i]);
    Set::adjust();
    std::vector<a4> res;
    if (k % 2) res.push_back({ Set::get_middle(), Set::get_middle(), 1, k });
    else res.push_back({ Set::get_middle(), Set::get_middle2(), 1, k });
    for (int i = k;i < n;++i) {
        Set::add(a[i]); Set::adjust();
        if ((k + 1) % 2) res.push_back({ Set::get_middle(), Set::get_middle(), i - k + 1, i + 1 });
        else res.push_back({ Set::get_middle(), Set::get_middle2(), i - k + 1, i + 1 });
        Set::del(a[i - k]); Set::adjust();
        if (k % 2) res.push_back({ Set::get_middle(), Set::get_middle(), i - k + 2, i + 1 });
        else res.push_back({ Set::get_middle(), Set::get_middle2(), i - k + 2, i + 1 });
    }
    // for (auto [x, y, l, r] : res) std::cout << x << ' ' << y << ' ' << l << ' ' << r << '\n';
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