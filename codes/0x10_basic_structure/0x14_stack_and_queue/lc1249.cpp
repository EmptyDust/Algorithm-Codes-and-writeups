#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int left = 0;
        int right = count(begin(s), end(s), ')');
        string ans = "";
        for (auto& c : s) {
            if (c == '(') {
                if (right > 0) {
                    ans += c;
                    left++;
                    right--;
                }
            } else if (c == ')') {
                if (left > 0) {
                    ans += c;
                    left--;
                } else {
                    right--;
                }
            } else {
                ans += c;
            }
        }
        return ans;
    }
};

/*
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string ans;
        stack<int> sk; //存储左括号的位置
        unordered_set<int> st; //保存待删除括号的位置 pos
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                sk.push(i);
            }
            else if(s[i] == ')'){
                if(sk.empty()){ //栈为空,当前括号无法匹配,将当前pos加入到哈希表中
                    st.insert(i);
                }
                else{
                    sk.pop();
                }
            }
        }
        while(!sk.empty()){
            st.insert(sk.top());
            sk.pop();
        }
        for(int i = 0; i < s.size(); i++){
            if(st.find(i) == st.end()) ans += s[i];
        }
        return ans;
    }
};
*/