#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 200008;
int nums[MAXN];
int zbs[MAXN];
int ans[MAXN];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int n;cin>>n;
    for(int i=0;i<n;++i)cin>>nums[i];
    iota(zbs,zbs+n,0);
    sort(zbs,zbs+n,[](int a,int b){return nums[a]>nums[b];});
    int sum=0,cnt=1;
    ans[zbs[0]]=0;
    for(int i=1;i<n;++i){
        if(nums[zbs[i]]==nums[zbs[i-1]]){
            cnt++;
            ans[zbs[i]]=sum;
        }
        else{
            sum+=cnt*nums[zbs[i-1]];
            cnt=1;
            ans[zbs[i]]=sum;
        }
    }
    for(int i=0;i<n;++i)cout<<ans[i]<<' ';
    return 0;
}