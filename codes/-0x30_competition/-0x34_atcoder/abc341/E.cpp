#include <bits/stdc++.h>
#define int long long 
using namespace std;
constexpr int MAXN = 1e6 + 10;
int nums[MAXN], m_tree[MAXN];
#define lowbit(x) x&-x
using pt = pair<int, int>;
int n, q;

void update(int x) {
    if (x <= 0 || x > n)return;
    int f = nums[x] = !nums[x];
    if (!f)f = -1;
    for (;x <= n;x += lowbit(x))
        m_tree[x] += f;
}

int qry(int x) {
    int ret = 0;
    for (;x;x -= lowbit(x))
        ret += m_tree[x];
    return ret;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> q;
    string s;cin >> s;
    for (int i = 0;i < n - 1;++i)if (s[i] == s[i + 1]) {
        update(i + 1);
    }
    int op, x, y;
    while (q--) {
        cin >> op >> x >> y;
        if (op == 1) {
            update(x - 1);
            update(y);
        }
        else {
            cout << ((qry(y - 1) - qry(x - 1)) ? "No" : "Yes") << '\n';
        }
    }
    return 0;
}