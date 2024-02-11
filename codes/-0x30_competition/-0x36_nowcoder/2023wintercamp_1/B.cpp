#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int MAXN = 1e5 + 10;
int u[MAXN], l[MAXN], ui, li;
using pt = pair<int, int>;

int f(int nums[MAXN], int x, int pos, int len) {
    while (pos != len && nums[pos] < x)pos++;
    return pos;
}

int solve() {
    int n;cin >> n;
    ui = li = 0;
    int x, y;
    int rans = 2, lans = 2, t = 3;
    for (int i = 0;i < n;++i) {
        cin >> y >> x;
        if (y == 1)u[ui++] = x;
        else l[li++] = x;
        if (!x)rans = lans = 1;
        if (x > 0)rans = 1;
        else lans = 1;
        if (x == 0 && y == 2 || abs(x) == 1 && y == 1)t--;
    }
    sort(u, u + ui);
    sort(l, l + li);
    for (int i = 0, j = 0;i < ui && j < li;) {
        if (abs(u[i] - l[j]) <= 1) {
            if (u[i] > 0)rans = 0;
            else lans = 0;
            if (u[i] > 0)break;
            i = f(u, 0, i, ui);
            j = f(l, 0, j, li);
        }
        else if (u[i] < l[j]) {
            i = f(u, l[j] - 1, i, ui);
        }
        else {
            j = f(l, u[i] - 1, j, li);
        }
    }
    return min(rans + lans, t);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t;cin >> t;
    while (t--) {
        cout << solve() << '\n';
    }
    return 0;
}