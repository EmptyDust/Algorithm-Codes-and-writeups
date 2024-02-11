#include <bits/stdc++.h>
#define int long long 
using namespace std;
constexpr int MAXN = 1e6;
int nums[MAXN], a, b, q[MAXN];
using pt = pair<int, int>;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n;cin >> n;
    vector<pt> pts;
    while (n--) {
        cin >> a >> b;
        if (a > b)swap(a, b);
        pts.push_back({ a,b });
    }
    sort(pts.begin(), pts.end());
    int r = 0;
    for (int i = 0;i < pts.size();++i) {
        while (r > 0 && pts[q[r - 1]].second < pts[i].first)r--;
        if (r && pts[i].second > pts[q[r - 1]].second) {
            cout << "Yes";
            return 0;
        }
        q[r++] = i;
    }
    cout << "No";
    return 0;
}