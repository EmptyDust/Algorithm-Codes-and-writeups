#include <bits/stdc++.h>
#define int long long 
#define x first
#define y second
using namespace std;

using pt = pair<int, int>;

void f(vector<pt>& pts, int x) {
    for (int i = 1;i < x;++i)
        if (sqrt(x * x - i * i) == (int)sqrt(x * x - i * i))
            pts.push_back({ i,sqrt(x * x - i * i) });
}

signed main() {
    ios::sync_with_stdio(false);
    int a, b;cin >> a >> b;
    vector<pt> pta, ptb;
    f(pta, a), f(ptb, b);
    for (pt A : pta)for (pt B : ptb) {
        if (A.x * B.y == A.y * B.x && A.x != B.y) {
            cout << "YES" << '\n';
            cout << 0 << ' ' << 0 << '\n';
            cout << A.x << ' ' << A.y << '\n';
            cout << B.y << ' ' << -B.x << '\n';
            return 0;
        }
        swap(A.x, A.y);
        if (A.x * B.y == A.y * B.x && A.x != B.y) {
            cout << "YES" << '\n';
            cout << 0 << ' ' << 0 << '\n';
            cout << A.x << ' ' << A.y << '\n';
            cout << B.y << ' ' << -B.x << '\n';
            return 0;
        }
    }
    cout << "NO";
    return 0;
}