#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 555555;
int nums[MAXN];
vector<int> ljlist[MAXN];
int ans;

int dp(int a,int par){
    if(ljlist[a].size()==1&&ljlist[a][0]==par){
        ans=max(ans,nums[a]);
        return nums[a];
    }
    if(ljlist[a].size()==2){
        for(int _:ljlist[a])if(_!=par){
            int dpr = dp(_,a);
            ans=max({ans,dpr+nums[a],nums[a]});
            return max(nums[a],dpr);
        }
    }
    //>=3
    int max1=INT_MIN,max2=INT_MIN;
    int maxf=INT_MIN,cnt=0,sum=0;
    for(int c:ljlist[a])if(c!=par){
        int tmp = dp(c,a);
        if(max2<tmp)
            max2=tmp;
        if(max1<max2)
            swap(max1,max2);
        if(tmp>0){
            cnt++;
            sum+=tmp;
        }
        else
            maxf=max(maxf,tmp);
    }
    //选择两个子节点：max1+max2
    //选择一个子节点：max1+nums[a]
    //选择多个子节点：cnt>2 sum+nums[a]
    ans=max({ans,nums[a]});
    if(max1!=INT_MIN){
        ans=max(ans,max1+nums[a]);
    if(max2!=INT_MIN)
        ans=max(ans,max1+max2);
    }
    if(cnt>2)
        ans=max(ans,sum+nums[a]);
    //2:sum+nums[a]
    //2:max1
    //2:nums[a]
    if(cnt==2&&maxf!=INT_MIN)
        ans=max(ans,maxf+sum+nums[a]);
    if(cnt==1)
        sum+=maxf;
    return max({max1,sum+nums[a],nums[a]});
};

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        for(int i=0;i<n;++i) ljlist[i].clear();
        for(int i=0;i<n;++i) cin>>nums[i];
        ljlist[0].push_back(-1);
        for(int i=0;i<n-1;++i){
            int a,b;
            cin>>a>>b;
            a--,b--;
            ljlist[a].push_back(b);
            ljlist[b].push_back(a);
        }
        ans=0;
        dp(0,-1);
        cout<<ans<<'\n';
    }
    return 0;
}