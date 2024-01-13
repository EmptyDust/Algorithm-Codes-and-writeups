#include<bits/stdc++.h>
#include<bits/extc++.h>
#define int long long

using namespace std;
using namespace __gnu_pbds;

#define x first
#define y second
#define ls(i) i<<1
#define rs(i) (i<<1)|1
#define lowbit(i) (i&(-i))

constexpr int MAXN = 6e6;
int nums[MAXN];

using pt = pair<int, int>;
using pat = pair<pt, int>;
using int_rb_tree = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

void solve() {
    string s1, s2;
    cin >> s1 >> s2;
    char a[26], b[26];
    for (int i = 0;i < 26;++i)a[i] = 0, b[i] = 0;
    for (char ch : s1)a[ch - 'a']++;
    for (char ch : s2)b[ch - 'a']++;
    bool f = true;
    for (int i = 0;i < 26;++i) {
        if (a[i] != b[i])f = false;
    }
    cout << (f ? "Yes" : "No") << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    solve();
    return 0;
}
