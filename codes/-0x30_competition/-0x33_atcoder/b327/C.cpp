#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<vector<int>> mp(9,vector<int>(9));
    for(int i=0;i<9;++i)
        for(int j=0;j<9;++j)
            cin>>mp[i][j];
    vector<int> temp(9);
    for(int i=0;i<9;++i){
        temp=mp[i];
        sort(temp.begin(),temp.end());
        cout<<endl;
        for(int j=1;j<=9;++j){
            if(temp[j-1]!=j){
                cout<<"No";
                return 0;
            }
        }
    }
    for(int i=0;i<9;++i){
        for(int j=0;j<9;++j){
            temp[j]=mp[j][i];
        }
        sort(temp.begin(),temp.end());
        cout<<endl;
        for(int j=1;j<=9;++j){
            if(temp[j-1]!=j){
                cout<<"No";
                return 0;
            }
        }
    }
    for(int i=0;i<9;i+=3){
        for(int j=0;j<9;j+=3){
            int k=0;
            for(int m=0;m<3;++m){
                for(int n=0;n<3;++n){
                    temp[k]=mp[i+m][j+n];
                    ++k;
                }
            }
            sort(temp.begin(),temp.end());
            for(int j=1;j<=9;++j){
                if(temp[j-1]!=j){
                    cout<<"No";
                    return 0;
                }
            }
        }
    }
    cout<<"Yes";
    return 0;
}