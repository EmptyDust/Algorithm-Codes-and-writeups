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
    std::string s;std::cin >> s;
    if (n == 1 || std::count(s.begin(), s.end(), s[0]) == n) {
        std::cout << -1 << '\n';
        return;
    }
    std::vector<int> a(n), cnt(3), ans;
    for (int i = 0;i < n;++i) {
        if (s[i] == 'T')a[i] = 0;
        if (s[i] == 'I')a[i] = 1;
        if (s[i] == 'L')a[i] = 2;
        cnt[a[i]]++;
    }
    // for (int i = 1;i < n;++i) {
    //     if (a[i] != a[i - 1]) {
    //         a3 vt;
    //         vt[a[i]] = 1;
    //         vt[a[i - 1]] = 1;
    //         for (int j = 0;j < 3;++j)if (!vt[j])p[j] = i;
    //     }
    // }
    while (cnt[0] != cnt[1] || cnt[1] != cnt[2]) {
        std::vector<int> idx = { 0,1,2 };
        ranges::sort(idx, [&](int x, int y) {return cnt[x] < cnt[y];});
        bool ok = false;
        int k = 0;
        while (!ok) {
            for (int i = 1;i < a.size();++i)if (a[i] != a[i - 1]) {
                int p = -1;
                a3 vt = { 0,0,0 };
                vt[a[i]] = 1;
                vt[a[i - 1]] = 1;
                for (int j = 0;j < 3;++j)if (!vt[j]) {
                    p = j;
                }
                // std::cout << p << ' ';
                if (p == idx[k]) {
                    // std::cout << i << '\n';
                    a.insert(a.begin() + i, p);
                    ok = true;
                    ans.push_back(i);
                    cnt[idx[k]]++;
                    break;
                }
            }
            // std::cout << '\n';
            k++;
            if (k >= 3) {
                std::cout << "k>=3";
                break;
            }
        }
        // a.insert(a.begin() + 1, 114514);
        // for (int x : a)std::cout << x << ' ';std::cout << '\n';
    }
    std::cout << ans.size() << '\n';
    for (int x : ans)std::cout << x << '\n';
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