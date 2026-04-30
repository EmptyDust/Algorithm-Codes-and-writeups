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



std::vector<int> tag;
int query(int x) {
    if (tag[x])return tag[x];
    std::cout << "? " << x + 1 << std::endl;
    int r;std::cin >> r;
    return tag[x] = r;
}

void solve() {
    int n, k;
    std::cin >> n >> k;
    if (n == k * 2) {
        std::cout << "! " << k << ' ' << k << std::endl;
        return;
    }
    std::vector<int> a, b;
    tag.assign(n, 0);
    for (int i = 0;i < k;++i) {
        a.push_back(query(i));
    }
    for (int i = n - k;i < n;++i) {
        b.push_back(query(i));
    }
    bool same = true;
    // int first_diff = -1;
    for (int i = 0, j = n % (n / k * k);i < k;i++, j = (j + 1) % k) {
        if (a[i] != b[j]) {
            // first_diff = i;
            same = false;
            break;
        }
    }
    // std::cout << first_diff << '\n';
    if (same) {
        std::cout << "! " << -1 << std::endl;
        return;
    }
    auto l = k, r = n - k;
    while (l < r) {
        auto mid = l + r >> 1;
        while (a[mid % k] == b[mid % k])mid--;
        if (query(mid) == query(mid + k))r = mid;
        else l = mid + 1;
    }
    int res = l;
    // std::cout << res - 1 << ' ' << n - k << '\n';
    while (query(res - 1) == query(res - 1 + k)) {
        res--;
    }    
    std::cout << res << ' ';
    if (query(res) != query(res - k)) {
        std::cout << "! " << res << ' ' << n - res << std::endl;
        return;
    }
    std::cout << "! " << -1 << std::endl;
    return;
}

signed main() {
    int t;std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

// 1 2 1 2 2 1
// 1 2 1 1 2