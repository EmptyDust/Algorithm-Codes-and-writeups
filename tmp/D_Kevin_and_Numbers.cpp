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
    int n, m;std::cin >> n >> m;
    std::vector<int> a(n), b(m);
    for (int& x : a)std::cin >> x;
    for (int& x : b)std::cin >> x;
    std::map<int, i64> cnt, bcnt;
    std::set<int, std::greater<int>> st;
    for (int& x : a)cnt[x]++;
    for (int& x : b)bcnt[x]++, st.insert(x);
    while (st.size()) {
        int top = *st.begin();
        st.erase(st.begin());
        i64 c = bcnt[top];
        i64 nc = cnt[top];
        if (nc > c) {
            std::cout << "No";
            return;
        }
        cnt.erase(top);
        i64 la = c - nc;
        if (la) {
            if (top <= 1) {
                std::cout << "No";
                return;
            }
            if (top % 2) {
                st.insert(top / 2);
                st.insert(top / 2 + 1);
                bcnt[top / 2] += la;
                bcnt[top / 2 + 1] += la;
            }
            else {
                st.insert(top / 2);
                bcnt[top / 2] += la * 2;
            }
        }
    }
    if (cnt.size() || st.size()) {
        std::cout << "No";
        return;
    }
    std::cout << "Yes";
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