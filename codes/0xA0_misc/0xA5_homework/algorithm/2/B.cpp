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

std::map<std::string, int> memo;

int solve(std::string s) {
    if (s.empty()) {
        return 0;
    }
    if (memo.count(s)) {
        return memo[s];
    }

    int n = s.length();
    int min_folds = 1000000;

    for (int i = 0; i < n; ++i) {
        int lenL = i;
        int lenR = n - 1 - i;

        bool f = true;

        for (int k = 1; k <= std::min(lenL, lenR); ++k) {
            if (s[i - k] == s[i + k]) {
                f = false;
                break;
            }
        }

        if (f) {
            std::string ns;
            if (lenL >= lenR) {
                ns = s.substr(0, lenL);
            }
            else {
                ns = s.substr(i + 1);
            }

            min_folds = std::min(min_folds, 1 + solve(ns));
        }
    }

    return memo[s] = min_folds;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t = 1;
    while (t--) {
        std::string s;std::cin >> s;
        std::cout << solve(s) << '\n';
    }
    return 0;
}