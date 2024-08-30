#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<int, char>;
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
    std::map<char, int> mp;
    for (auto ch : s)mp[ch]++;
    std::priority_queue<pii> pq;
    for (auto [ch, cnt] : mp)pq.push({ cnt,ch });
    std::string ans;
    while (pq.size()) {
        auto [cnt, ch] = pq.top();
        pq.pop();
        if (ans.empty() || ans.back() != ch || pq.empty()) {
            ans += ch;
            cnt--;
            if (cnt)pq.push({ cnt,ch });
        }
        else {
            auto [cnt2, ch2] = pq.top();
            pq.pop();
            pq.push({ cnt,ch });
            ans += ch2;
            cnt2--;
            if (cnt2)pq.push({ cnt2,ch2 });
        }
    }
    std::cout << ans;
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