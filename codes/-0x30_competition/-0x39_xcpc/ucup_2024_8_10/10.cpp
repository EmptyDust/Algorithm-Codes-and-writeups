#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

#define int long long

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<i64, i64>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

// const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
// const int mod = 1e9 + 7;
const int mod = 998244353;

const int N = 63;
int lg2(i64 x) {
    int res = 0;
    for (int i = 0;i < N;++i)if (x >> i & 1)res = i;
    return res;
}

void solve() {
    int n;std::cin >> n;
    std::vector<i64> a(n);
    for (auto& x : a)std::cin >> x;
    std::vector<int> cnt(N);
    for (auto x : a)for (int s = 0;s < N;++s)if (x >> s & 1) {
        cnt[s]++;
    }
    std::vector<pii> ans;
    std::set<pii, std::greater<pii>> st;
    for (int i = 0;i < n;++i)st.insert({ a[i],i + 1 });
    while (st.size()) {
        auto [num1, p1] = *st.begin();
        st.erase(st.begin());
        auto [num2, p2] = *st.begin();
        st.erase(st.begin());
        // std::cout << num1 << ' ' << num2 << '\n';
        int p = lg2(num1);
        if (cnt[p] > 2) {
            std::cout << -1;
            return;
        }
        i64 num = 0;
        for (int s = 0;s < N;++s) if ((num1 >> s & 1) && (num2 >> s & 1)) {
            num |= 1ll << s;
            cnt[s] -= 2;
        }
        ans.push_back({ p1,num });
        num1 ^= num;
        num2 ^= num;
        if (num1)st.insert({ num1,p1 });
        if (num2)st.insert({ num2,p2 });
    }


    // std::vector<pii> res;
    // std::vector<bool> vis(30);
    // for (int i = 0;i < n;++i) {
    //     int x = a[i];
    //     for (int s = 29;s >= 0;--s)if (x >> s & 1) {
    //         if (!vis[s]) {
    //             res.push_back({ i + 1,1 << s });
    //             vis[s] = 1;
    //         }
    //     }
    // }
    std::cout << ans.size() << '\n';
    for (auto [p, num] : ans)std::cout << p << ' ' << num << '\n';
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