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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* pre=head,*temp=head,*l;
        while(temp){
            for(int i=0;i<k-1&&temp;++i)
                temp=temp->next;
            if(!temp)break;
            ListNode* temp1=temp;
            temp=temp->next;
            temp1->next=nullptr;
            if(pre==head)
                head=reverseList(pre);
            else
                l->next=reverseList(pre);
            l=pre;
            pre=temp;
        }
        l->next=pre;
        return head;
    }
    
    ListNode* reverseList(ListNode* head) {
        if(!head||!head->next)return head;
        ListNode* temp1 = head,*temp2=head->next,*temp3=head->next->next;
        head->next=nullptr;
        while(temp2){
            temp2->next=temp1;
            temp1=temp2;
            temp2=temp3;
            if(temp3)
                temp3=temp3->next;
        }
        return temp1;
    }
};