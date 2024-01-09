#include<bits/stdc++.h>
#define int long long 
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    int n;cin >> n;
    for (int i = 0;i <= n;++i) {
        for (int j = 0;j <= n;++j) {
            if (i + j > n)continue;
            for (int k = 0;k <= n;++k) {
                if (i + j + k > n)continue;
                cout << i << ' ' << j << ' ' << k << '\n';
            }
        }
    }
    return 0;
}