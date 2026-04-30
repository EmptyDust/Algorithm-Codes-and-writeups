#include <bits/stdc++.h>
#define int long long 
using namespace std;
constexpr int MAXN = 64 + 10;
int f, n;
set<int> st;
using pt = pair<int, int>;

bool check(int x) { return (x + 2) / 2 >= f && x % 2 == 0; }

void cal(int x) {
    for (int i = 1;i <= sqrt(x);++i)if (x % i == 0) {
        if (check(i))
            st.insert(i);
        if (check(x / i))
            st.insert(x / i);
    }
}

void solve() {
    cin >> n >> f;
    cal(n - f);cal(n + f - 2);
    cout << st.size();
}

signed main() {
    ios::sync_with_stdio(false);
    int t;cin >> t;
    while (t--) {
        st.clear();
        solve();
        cout << '\n';
    }
    return 0;
}