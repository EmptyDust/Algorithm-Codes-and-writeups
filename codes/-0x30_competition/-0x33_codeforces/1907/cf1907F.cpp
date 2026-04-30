#include <bits/stdc++.h>
#define int long long
using namespace std;
int nums[1000000];
int l,r;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int n;cin>>n;
    while(n--){
        int t;cin>>t;
        for(int i=0;i<t;++i)cin>>nums[i];
        l=0,r=t-1;
        while(l<t-1&&nums[l+1]>=nums[l])l++;
        if(l==t-1){
            cout<<0<<'\n';
            continue;
        }
        while(r>0&&nums[r-1]<=nums[r])r--;
        int ans=INT_MAX;
        if(l==r-1&&nums[0]>=nums[t-1])
            ans=min(t-r,2+r);

        l=0,r=t-1;
        while(l<t-1&&nums[l+1]<=nums[l])l++;
        if(l==t-1){
            cout<<1<<'\n';
            continue;
        }
        while(r>0&&nums[r-1]>=nums[r])r--;
        if(l==r-1&&nums[0]<=nums[t-1])
            ans=min({ans,1+t-r,1+r});
        if(ans!=INT_MAX)
            cout<<ans<<'\n';
        else
            cout<<-1<<'\n';
    }
    return 0;
}
/*
显而易见，如果你将数列首尾相连，将它看作一个环，那么必然应在ai处开始递增或递减直到ai-1为止，否则就说明不可能
回到问题本身，可以分两种情况讨论，
以下左指针为i，右指针为j
左侧单调上升（从左往右看）且右侧单调下降（从右往左看）且a0>=at-1(t是数列的大小)且i=j-1,则ans=min(t-r,2+r)
或者左侧单调下降（从左往右看）且右侧单调上升（从右往左看）且a0<=at-1且i=j-1，则ans=min({ans,1+t-r,1+r})
举例：
4 1 3 4 4
第一种情况中i=0,j=1，可以由此算出答案
第二种情况中i=1,j=3，显然不满足i=j-1条件
输出答案即可

3 7 10 5
第一种情况中i=2,j=3,但3<5，因此不成立
第二种情况中i=0,j=2,显然不成立
因此输出-1

我建议你可以画一些图，如果你有较好的几何理解，我认为这道题是极其显然的。
translate by google
My English is not good,so i have to use google translation.(But this paragraph is wrote by myself,you can realize how poor it is lol),the ispissima verba is on top,if you have friend who can read Chinese,that will be wonderful.


solution:
Obviously, if you connect the sequence end to end and treat it as a ring, then it must start increasing or decreasing at ai until ai-1, otherwise it means it is impossible.
Back to the problem itself, it can be discussed in two situations:
The left pointer is i and the right pointer is j
The left side increases monotonically (looking from left to right) and the right side decreases monotonically (looking from right to left) and a0>=at-1 (t is the size of the sequence) and i=j-1, then ans=min(t-r ,2+r)
Or the left side decreases monotonically (looking from left to right) and the right side increases monotonically (looking from right to left) and a0<=at-1 and i=j-1, then ans=min({ans,1+t-r, 1+r})
Example:
4 1 3 4 4
In the first case, i=0,j=1, the answer can be calculated from this
In the second case, i=1,j=3, obviously the condition of i=j-1 is not satisfied.
Just output the answer

3 7 10 5
In the first case, i=2, j=3, but 3<5, so it is not true.
In the second case, i=0, j=2, which is obviously not true.
So the output is -1

I suggest you draw some pictures. If you have a good understanding of geometry, I think this question is extremely obvious.
*/