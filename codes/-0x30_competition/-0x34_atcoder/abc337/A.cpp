#include <bits/stdc++.h>
#define int long long 
using namespace std;
constexpr int MAXN = 1e6;
int nums[MAXN];
using pt = pair<int, int>;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n;cin >> n;
    int cnta = 0, cntb = 0;
    for (int i = 0;i < n;++i) {
        int a, b;cin >> a >> b;
        cnta += a;
        cntb += b;
    }
    if (cnta == cntb) {
        cout << "Draw";
        return 0;
    }
    cout << (cnta > cntb ? "Takahashi" : "Aoki");

    return 0;
}