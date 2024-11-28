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

void solve() {
    int n;std::cin >> n;
    std::vector<int> a(n);
    for (int& x : a)std::cin >> x;
    std::vector<int> odd, even;
    for (int i = 0;i < n;i += 2) {
        if (i + 1 < n && a[i] == a[i + 1]) {
            even.push_back(i);
        }
    }
    for (int i = 1;i < n;i += 2) {
        if (i + 1 < n && a[i] == a[i + 1])
            odd.push_back(i);
    }
    std::vector<int> cnt(n + 1);
    int max = 0;
    for (int i = 0, j = 0;j < odd.size();++j) {
        if (j && odd[j - 1] + 2 != odd[j]) {
            while (i < j) {
                cnt[a[odd[i]]]--;
                i++;
            }
        }
        while (cnt[a[odd[j]]]) {
            cnt[a[odd[i]]]--;
            i++;
        }
        cnt[a[odd[j]]]++;
        max = std::max(max, (j - i + 1) * 2);
    }
    cnt.assign(n + 1, 0);
    for (int i = 0, j = 0;j < even.size();++j) {
        if (j && even[j - 1] + 2 != even[j]) {
            while (i < j) {
                cnt[a[even[i]]]--;
                i++;
            }
        }
        while (cnt[a[even[j]]]) {
            cnt[a[even[i]]]--;
            i++;
        }
        cnt[a[even[j]]]++;
        max = std::max(max, (j - i + 1) * 2);
    }
    std::cout << max;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t = 1;//std::cin >> t;
    while (t--) {
        solve();
        std::cout << '\n';
    }
    return 0;
}