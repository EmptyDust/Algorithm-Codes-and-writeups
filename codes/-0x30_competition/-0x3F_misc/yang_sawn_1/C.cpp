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
    int n, k;std::cin >> n >> k;
    std::vector<int> a(n), p(n), vis(n);
    for (int& x : a)std::cin >> x;
    std::deque<int> dq;
    for (int i = 0, j = 0, pre = -1, pcnt = 0;i < n;++i) {
        while (dq.size() && dq.front() < i) {
            dq.pop_front();
        }
        while (j < n && j < i + k) {
            while (dq.size() && a[dq.back()] < a[j]) {
                dq.pop_back();
            }
            dq.push_back(j);
            j++;
        }
        if (pre != -1 && pcnt && a[pre] >= a[dq.front()]) {
            if (dq.front() == i && a[pre] == a[i]) {
                pcnt = k;
            }
            else a[i] = a[pre];
            pcnt--;
            continue;
        }
        // if (i == 2)std::cout << dq.front() << '\n';
        pcnt = k - 1;
        pre = dq.front();
        for (;i < dq.front();++i) {
            a[i] = a[pre];
            pcnt--;
        }
    }
    for (int x : a)std::cout << x << ' ';
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