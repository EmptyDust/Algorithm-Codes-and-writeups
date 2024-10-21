#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<int, int>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
// const int mod = 1e9 + 7;
const int mod = 998244353;

namespace Set {
    const i64 kInf = 1e18 + 2077;
    std::multiset<i64> less, greater;
    i64 less_sum = 0, greater_sum = 0;
    void init() {
        less.clear(), greater.clear();
        less.insert(-kInf), greater.insert(kInf);
        less_sum = 0, greater_sum = 0;
    }
    void adjust() {
        while (less.size() > greater.size() + 1)
        {
            std::multiset<i64>::iterator it = (--less.end());
            greater.insert(*it);
            greater_sum += *it;
            less_sum -= *it;
            less.erase(it);
        }
        while (greater.size() > less.size()) {
            std::multiset<i64>::iterator it = greater.begin();
            less.insert(*it);
            less_sum += *it;
            greater_sum -= *it;
            greater.erase(it);
        }
    }
    void add(i64 val_) {
        if (val_ <= *greater.begin()){
            less_sum += val_;
            less.insert(val_);
        }
        else {
            greater_sum += val_;
            greater.insert(val_);
        }
        adjust();
    }
    void del(i64 val_) {
        std::multiset<i64>::iterator it = less.lower_bound(val_);
        if (it != less.end()) {
            less_sum -= *it;
            less.erase(it);
        }
        else {
            it = greater.lower_bound(val_);
            greater_sum -= *it;
            greater.erase(it);
        }
        adjust();
    }
    i64 get_middle() {
        return *less.rbegin();
    }
    i64 get_ans(){
        i64 mid = get_middle();
        i64 ans = mid * less.size() - less_sum + greater_sum - mid * greater.size();
        return ans;
    }
}

void solve() {
    i64 n, k;std::cin >> n >> k;
    std::vector<i64> a(n);
    for (auto& x : a)std::cin >> x;
    for (int i = 0;i < n;++i)a[i] -= i;

    Set::init();
    int ans = 0;
    for (int l = 0, r = 0;l < n;++l){
        while (r < n && Set::get_ans() <= k){
            Set::add(a[r]);
            r++;
        }
        if (Set::get_ans() > k){
            Set::del(a[r - 1]);
            r--;
        }
        ans = std::max(ans, r - l);
        Set::del(a[l]);
    }
    std::cout << ans;

    // i64 l = 1, r = n + 1;
    // auto check = [&](auto len)->bool {
    //     Set::init();
    //     for (int i = 0;i < len;++i){
    //         Set::add(a[i]);
    //     }
    //     i64 min = Set::get_ans();
    //     for (int i = len;i < n;++i){
    //         Set::add(a[i]);
    //         Set::del(a[i - len]);
    //         min = std::min(min, Set::get_ans());
    //     }
    //     return min > k;
    //     };
    // while (l < r) {
    //     auto mid = l + r >> 1;
    //     if (check(mid))r = mid;
    //     else l = mid + 1;
    // }
    // std::cout << l - 1;
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