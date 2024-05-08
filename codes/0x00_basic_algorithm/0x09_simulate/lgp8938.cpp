#include <bits/stdc++.h>

using namespace std;
#define int long long
double l=0, r=1e9;
int n, m, a[100010];

signed main() {
    cin>>n>>m;
    for (int i=1; i<=n; ++i) {
        cin>>a[i];
        l=max(l,m/double(i*a[i]));
        if (a[i]-1)
            r=min(r,m/double(i*(a[i]-1)));
    }
    int tot=0;
    for (int i=l; i<r; ++i) {
        if (i>=l && i<r) ++tot;
    }
    if (r>=1e9) {
        cout<<"xiaogougege";
        return 0;
    }
    cout<<tot;
}