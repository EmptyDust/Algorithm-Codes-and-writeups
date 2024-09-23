#include<bits/stdc++.h>
#define int long long 
#define pb push_back
#define pii pair<int,int>
using namespace std;
bool debug = 1;
#define dbg(x) if(debug) cerr<<BRIGHT_CYAN<<#x<<COLOR_RESET<<" = "<<(x)<<NORMAL_FAINT<<COLOR_RESET<<endl;
const string COLOR_RESET = "\033[0m", BRIGHT_CYAN = "\033[1;36m", NORMAL_FAINT = "\033[0;2m";

const int N = 2033;

int n, a[N], rk[N], s[N], b[N][N], c[N][N], sb[N][N];

bool check(int x){
    for (int i = 1; i <= n; i++){
        s[i] = s[i - 1] + (a[i] > x);
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j++)
            b[i][j] = !(j - i + 1 - s[j] + s[i - 1] >= (j - i + 2) / 2);
    /*for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cout << b[i][j] << " \n"[j == n];*/
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            sb[i][j] = sb[i - 1][j] + sb[i][j - 1] + b[i][j] - sb[i - 1][j - 1];
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j++){
            c[i][j] = (sb[j][j] - sb[i - 1][j] - sb[j][i - 1] + sb[i - 1][i - 1]);
            int sz = (j - i + 2) * (j - i + 1) / 2;
            if(sz - c[i][j] >= (sz + 1) / 2)
                cnt++;
        }
    return cnt >= (n * (n + 1) / 2 + 1) / 2;
}
void solve(){
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i], rk[i] = a[i];
    sort(rk + 1, rk + n + 1);
    int l = 1, r = n, mid;
    while(l < r){
        mid = (l + r) >> 1;
        if(check(rk[mid]))
            r = mid;
        else
            l = mid + 1;
    }
    cout << rk[l];
}


signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t = 1;
    while(t--)
        solve();
    return 0;
}

//__builtin_popcountll()
// cout<<fixed<<setprecision(2);

