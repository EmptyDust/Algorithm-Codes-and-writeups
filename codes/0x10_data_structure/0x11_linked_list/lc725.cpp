#include <bits/stdc++.h>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode* t = new ListNode(0,head),*temp=t->next;
        int cnt=0;
        while(temp){++cnt;temp=temp->next;}
        int a=cnt%k;
        vector<int> ans(k);
        vector<ListNode*> ret(k);
        temp=t;
        for(int i=0;i<k;++i){
            ans[i]=cnt/k;
            if(a){--a;++ans[i];}
            if(temp->next){
                ret[i]=temp->next;
                ListNode* temp1=temp;
                temp=temp->next;
                temp1->next=nullptr;
            }
            for(int j=1;j<ans[i];++j)
                temp=temp->next;
        }
        for(int num:ans)cout<<num<<" ";
        return ret;
    }
};