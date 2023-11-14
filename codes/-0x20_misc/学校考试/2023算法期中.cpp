/*
设某一机器由几个部件组成，部件编号为1-n，每种部件都可以从m个不同的优应商处购得，供应商编号1-m.
设w[i][j]从供应商处购得的部件i的重量，c[i][j]是相应的价格。对于给定的机器部件重量和机器部件价格，计算总价不超过
cost的最小重量机器设计，可以在同一供应商处购得多个部件。
输入描述：第1行输入3个整数n、m和cost，接下来n行输入w[i][j]（每行m个整数），最后n行输入c[i][j]（每行m个整数）
这里1<=n.m<=100.
输出述:输出的第1行包括n个整数，表示每个对应的供应商编号，第2行为对应的重量。
输入样例：
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m,cost;
    cin>>n>>m>>cost;
    vector<vector<int>> w(n,vector<int>(m));
    vector<vector<int>> c(n,vector<int>(m));
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j)
            cin>>w[i][j];
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j)
            cin>>c[i][j];
    vector<int> ans(n,-1);int minw=INT_MAX;
    vector<int> temp(n);
    function<void(int,int,int)> dfs = [&](int price,int i,int weight)->void{
        if(price>cost||weight>minw)return;
        if(i==n){
            if(weight<minw){
                minw=weight;
                ans=temp;
            }
            return;
        }
        for(int j=0;j<m;++j){
            temp[i]=j+1;
            dfs(price+c[i][j],i+1,weight+w[i][j]);
        }
    };
    dfs(0,0,0);
    for(int num:ans)cout<<num<<" ";
    cout<<endl<<minw;
    return 0;
}