class Solution {
public:
    int distributeCandies(int n, int limit) {
        int cnt=0;
        for(int i=0;i<=limit;++i){
            for(int j=0;j<=limit;++j){
                int f=n-i-j;
                if(f>=0&&f<=limit)cnt++;
            }
        }
        return cnt;
    }
};