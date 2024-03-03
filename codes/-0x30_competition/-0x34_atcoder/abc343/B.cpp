#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int MAXN = 1e6 + 10;
int nums[MAXN], n;
using pt = pair<int, int>;

signed main() {
    ios::sync_with_stdio(false);
    int n;cin >> n;
    int tmp;
    for (int i = 0;i < n;++i) {
        for (int j = 0;j < n;++j) {
            cin >> tmp;
            if (tmp) cout << j + 1 << ' ';
        }
        cout << endl;
    }
    return 0;
}