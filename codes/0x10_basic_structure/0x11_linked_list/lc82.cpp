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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head||!head->next)return head;
        while(head->val==head->next->val){
            while(head->val==head->next->val){
                head=head->next;
                if(!head->next)return nullptr;
            }
            head=head->next;
            if(!head->next)return head;
        }
        ListNode* temp1=head;
        ListNode* temp2=head;
        while(temp1->next){
            if(temp1->val!=temp1->next->val){
                temp2=temp1;
                temp1=temp1->next;
                continue;
            }
            while(temp1->next&&temp1->val==temp1->next->val){
                temp1=temp1->next;
            }
            temp1=temp1->next;
            temp2->next=temp1;
            if(!temp1)return head;
        }
        return head;
    }
};