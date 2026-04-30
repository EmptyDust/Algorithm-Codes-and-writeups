#include <bits/stdc++.h>
#define int long long 
using namespace std;
constexpr int MAXN = 5e5;
int nums[MAXN];

void solve() {
    int n;cin >> n;
    int tmp;
    int sum = 0;
    bool f = false;
    set<int> st;st.insert(0);
    for (int i = 0;i < n;++i) {
        cin >> tmp;
        if (i & 1)sum += tmp;
        else sum -= tmp;
        if (st.count(sum))
            f = true;
        else
            st.insert(sum);
    }
    cout << (f ? "YES" : "NO");
}

signed main() {
    ios::sync_with_stdio(false);
    int t;cin >> t;
    while (t--) {
        solve();
        cout << '\n';
    }
    return 0;
}