#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        vector<int> nt(b.length());
        nt[0]=-1;
        for(int i=0,j=-1;i<b.length()-1;){
            if(j==-1||b[i]==b[j]){
                ++i;++j;
                nt[i]=j;
            }
            else
                j=nt[j];
        }
        int n=a.length(),count=0;
        string temp=a;
        for(int i=0,j=0;j<(int)b.length();){
                
            if(i==a.length()){
                count++;
                if(a.length()<=b.length()+temp.length())
                    a+=temp;
                else
                    return -1;
            }
            if(j==-1||a[i]==b[j]){
                ++i;++j;
            }
            else
                j=nt[j];
        }
        return count+1;
    }
};