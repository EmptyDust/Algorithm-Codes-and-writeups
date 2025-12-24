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

// 5 4
// 5 5 5 0
// 5 5 3 2

// 10101

// 21 4
// 21 21 21 0
// 15 10 5 21

#define lowbit(x) x&-x

// 10111
// 01111

void solve() {
    i64 n, k;std::cin >> n >> k;
    if (k % 2) {
        for (int i = 0;i < k;++i) std::cout << n << " ";
    }
    else {
        std::vector<int> nums;
        for (int i = std::__lg(n);i >= 0;--i) {
            int sz = nums.size();
            if (n >> i & 1) {
                if (sz < k) {
                    nums.push_back(n ^ 1 << i);
                }
                else {
                    nums.back() ^= 1 << i;
                }
            }
            else {
                for (int j = 1;j < sz;j += 2) {
                    nums[j - 1] ^= 1 << i;
                    nums[j] ^= 1 << i;
                }
            }
        }

        for (int i = 0;i < k;++i) {
            if (i < nums.size()) std::cout << nums[i] << " ";
            else std::cout << n << ' ';
        }
    }
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