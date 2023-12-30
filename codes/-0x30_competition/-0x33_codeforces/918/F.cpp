#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define int long long 
#define pre first
#define suf second

using namespace std;
using namespace __gnu_pbds;

constexpr int MAXN = 5e5;
using pt = pair<int, int>;
pt pts[MAXN];

int zbspre[MAXN], zbssuf[MAXN];

void solve() {
    int n;cin >> n;
    for (int i = 0;i < n;++i)
        cin >> pts[i].pre >> pts[i].suf;
    sort(pts, pts + n);
    int sum = 0;
    tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> st;
    for (int i = 0;i < n;++i) {
        sum += st.size() - st.order_of_key(pts[i].suf);
        st.insert(pts[i].suf);
    }
    cout << sum;
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