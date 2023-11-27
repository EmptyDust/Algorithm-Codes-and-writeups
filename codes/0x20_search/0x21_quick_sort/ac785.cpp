#include <bits/stdc++.h>
using namespace std;

void quick_sort(vector<int>& list,int pre,int suf){
    if(pre>=suf)return;
    int i=pre-1;
    int j=suf+1;
    int temp=pre+suf>>1;
    while(i<j){
        do i++; while(list[i]<list[temp]);
        if(i<j) swap(list[i],list[temp]);
        temp=i;
        do j--; while(list[j]>list[temp]);
        if(i<j) swap(list[j],list[temp]);
        temp=j;
    }
    quick_sort(list,pre,i-1);
    quick_sort(list,i+1,suf);
}
int main(){
    int n;
    cin>>n;
    vector<int> list(n);
    int j=0;
    for(int i=0;i<n;++i) cin>>list[i];
    quick_sort(list,0,n-1);
    for(int num:list) cout<<num<<" ";
    return 0;
}