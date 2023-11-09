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
    ListNode* partition(ListNode* head, int x) {
        if(!head||!head->next)return head;
        ListNode* greater = new ListNode(),*temp2=greater;
        ListNode* k = new ListNode(0,head);
        ListNode* temp = k;
        while(temp->next){
            while(temp->next&&temp->next->val>=x){
                temp2->next=temp->next;
                temp2=temp2->next;
                temp->next=temp->next->next;
            }
            if(temp->next)
            temp=temp->next;
        }
        temp->next=greater->next;
        temp2->next=nullptr;
        return k->next;
    }
};