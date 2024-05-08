#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=1e6+7;
const int mod =114514191;//9810好臭
int a[MAXN];
int b[MAXN];
struct Node
{
    int i;
    int j;
    int value;
    bool operator()(Node x,Node y){
        return x.value<y.value;
    }
};

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    signed n,m,k;
    cin>>n>>m>>k;
    for(int i=0;i<n;++i)cin>>a[i];
    for(int i=0;i<m;++i)cin>>b[i];
    sort(a,a+n);
    sort(b,b+m);
    reverse(a,a+n);
    reverse(b,b+m);
    priority_queue<Node,vector<Node>,Node> pq;
    for (int i = 0; i < n; i++)
    {
        pq.push({i,0,a[i]+b[0]});
    }
    int sum = 0;
    for(signed i=0;i<k;++i){
        Node cut = pq.top();
        pq.pop();
        sum+=cut.value%mod;
        sum%=mod;
        if(cut.j<m-1){
            pq.push({cut.i,cut.j+1,a[cut.i]+b[cut.j+1]});
        }
    }
    cout<<sum;
    return 0;
}