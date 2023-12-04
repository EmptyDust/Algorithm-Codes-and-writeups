#include <bits/stdc++.h>
#define int long long
#define LL long long
using namespace std;
const int mod = 1e9+7;

int pw(int n){
    if(n==1)return 2;
    if(n%2==1)return pw(n/2)%mod*pw(n/2)%mod*2;
    else return pw(n/2)%mod*pw(n/2)%mod;
}

int qmi(int a, int k, int mod) {
    int res = 1 % mod;
    while (k) {
        if (k & 1) res = (LL)res * a % mod;
        a = (LL)a * a % mod;
        k >>= 1;
    }
    return res;
}

// 定义求解
int C(int a, int b) {
    if (b > a) return 0;
    int res = 1;
    for (int i = 1, j = a; i <= b; ++i, --j) {
        res = (LL)res * j % mod;
        res = (LL)res * qmi(i, mod - 2, mod) % mod;
    }
    return res;
}

int lucas(LL a, LL b) {               // 注意LL参数类型
    if (a < mod && b < mod) return C(a, b);
    return (LL)C(a % mod, b % mod) * lucas(a / mod, b / mod) % mod;     // 递归让其到p范围内求解
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n,x,y,z;
    cin>>n>>x>>y>>z;
    int sum = (pw(n)-1)%mod;
    //cout<<sum<<endl;
    sum-=lucas(n,x);
    if(sum<0)sum+=mod;
    sum-=lucas(n,y);
    if(sum<0)sum+=mod;
    sum-=lucas(n,z);sum%=mod;
    if(sum<0)sum+=mod;
    cout<<sum;
    return 0;
}