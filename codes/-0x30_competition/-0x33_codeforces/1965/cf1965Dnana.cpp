#include <bits/stdc++.h>
//using i64 = long long;
#define int long long
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
int n;
using pii = std::pair<int, int>;
using namespace std;
void solve() {
    int n, k;cin >> n >> k;
    vector<int> ans;
    cout << 23 << endl;
    int t = -1, m = k;
    while (k)t++, k >>= 1;
    for (int i = 0;i <= 20;++i)
        if (i != t)
            ans.push_back(1ll << i);
    ans.push_back(m + 1);
    ans.push_back(m - (1ll << t));
    ans.push_back((1ll << t) + (1ll << (t + 1)));
    for (auto& it : ans)cout << it << " ";
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